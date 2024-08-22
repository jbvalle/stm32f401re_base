import re
import argparse
import glob
import os

def parse_header_file(header_file):
    # Regular expressions to match structs and fields
    struct_re = re.compile(r'\s*typedef\s+struct\s*{(.*?)}\s*(\w+);', re.DOTALL)
    field_re = re.compile(r'\s*volatile\s+uint32_t\s+(\w+)(\[\d*\])?\s*;')
    
    struct_offsets = {}
    
    with open(header_file, 'r') as file:
        content = file.read()
        
        # Find all structs
        for struct_match in struct_re.finditer(content):
            struct_body = struct_match.group(1)
            struct_name = struct_match.group(2)
            
            # Find all fields in the struct
            offsets = {}
            offset = 0
            name_count = {}
            for field_match in field_re.finditer(struct_body):
                field_name = field_match.group(1)
                array_size = field_match.group(2)
                
                # Handle duplicate field names
                if field_name in name_count:
                    name_count[field_name] += 1
                    unique_field_name = f'{field_name}_{name_count[field_name]}'
                else:
                    name_count[field_name] = 0
                    unique_field_name = field_name

                if array_size:
                    # Handle arrays
                    try:
                        size = int(array_size.strip('[]'))
                    except ValueError:
                        size = 1  # Default to 1 if array size is unspecified
                    # Array fields take up `size` * 4 bytes
                    for i in range(size):
                        offsets[f'{unique_field_name}[{i}]'] = hex(offset + i * 4)
                    offset += size * 4
                else:
                    # Non-array fields
                    offsets[unique_field_name] = hex(offset)
                    offset += 4  # assuming all fields are 4 bytes
                
            struct_offsets[struct_name] = offsets

    return struct_offsets

def parse_vector_table(file_content):
    # Regular expression to match vector table definition
    vector_table_re = re.compile(r'__attribute__\s*\(\(section\(".isr_vector"\)\)\)\s*void\s*\(\*\s*const\s*vector_table\[\]\)\(void\)\s*=\s*{(.*?)};', re.DOTALL)
    vector_table_match = vector_table_re.search(file_content)
    
    if not vector_table_match:
        return {}
    
    # Extract handlers inside the vector table
    handlers_block = vector_table_match.group(1).strip()
    handlers = [handler.strip() for handler in handlers_block.split(',')]
    
    # Assign offsets to each handler (4 bytes per handler)
    vector_table_offsets = {}
    name_count = {}
    
    for i, handler in enumerate(handlers):
        # If the handler name appears more than once, append an index to it
        if handler in name_count:
            name_count[handler] += 1
            unique_handler = f'{handler}_{name_count[handler]}'
        else:
            name_count[handler] = 0
            unique_handler = handler
        
        vector_table_offsets[unique_handler] = hex(i * 4)
    
    return {'vector_table': vector_table_offsets}

def write_output(output_file, struct_offsets):
    with open(output_file, 'w') as file:
        for struct_name, fields in struct_offsets.items():
            file.write(f'{struct_name}:\n')
            for field_name, offset in fields.items():
                file.write(f' {field_name} : {offset}\n')
            file.write('\n')

def process_files(input_files):
    all_struct_offsets = {}
    
    for input_file in input_files:
        if os.path.isfile(input_file):
            with open(input_file, 'r') as file:
                file_content = file.read()
            
            # Parse both structs and vector table
            struct_offsets = parse_header_file(input_file)
            vector_table_offsets = parse_vector_table(file_content)
            
            # Merge both results
            all_struct_offsets.update(struct_offsets)
            all_struct_offsets.update(vector_table_offsets)
    
    return all_struct_offsets

def main():
    parser = argparse.ArgumentParser(description='Extract struct field offsets and vector table entries from C header and source files.')
    parser.add_argument('input_files', nargs='+', help='Input files to parse (supports glob patterns).')
    parser.add_argument('-o', '--output', type=str, required=True, help='Output file to write the results.')

    args = parser.parse_args()
    
    # Resolve file paths using glob patterns
    input_files = []
    for pattern in args.input_files:
        input_files.extend(glob.glob(pattern))
    
    struct_offsets = process_files(input_files)
    write_output(args.output, struct_offsets)

if __name__ == '__main__':
    main()


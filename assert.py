import re
import argparse
import glob
import os

# Function to parse structs
def parse_header_file(header_file):
    struct_re = re.compile(r'\s*typedef\s+struct\s*{(.*?)}\s*(\w+);', re.DOTALL)
    field_re = re.compile(r'\s*volatile\s+uint32_t\s+(\w+)(\[\d*\])?\s*;')
    
    struct_offsets = {}
    
    with open(header_file, 'r') as file:
        content = file.read()
        
        for struct_match in struct_re.finditer(content):
            struct_body = struct_match.group(1)
            struct_name = struct_match.group(2)
            
            offsets = {}
            offset = 0
            for field_match in field_re.finditer(struct_body):
                field_name = field_match.group(1)
                array_size = field_match.group(2)
                
                if array_size:
                    try:
                        size = int(array_size.strip('[]'))
                    except ValueError:
                        size = 1
                    for i in range(size):
                        offsets[f'{field_name}[{i}]'] = hex(offset + i * 4)
                    offset += size * 4
                else:
                    offsets[field_name] = hex(offset)
                    offset += 4
                
            struct_offsets[struct_name] = offsets

    return struct_offsets

# Function to parse the vector table
def parse_vector_table(file_content):
    vector_table_re = re.compile(r'__attribute__\s*\(\(section\(".*?"\)\)\)\s*void\s*\(\*\s*const\s*(\w+)\[\]\)\(void\)\s*=\s*{(.*?)};', re.DOTALL)
    entry_re = re.compile(r'(\w+|0)')
    
    vector_table_offsets = {}
    
    match = vector_table_re.search(file_content)
    if match:
        table_name = match.group(1)
        entries = match.group(2).split(',')
        offsets = {}
        offset = 0
        for i, entry in enumerate(entries):
            entry = entry.strip()
            offsets[f'{entry}'] = hex(offset)
            offset += 4  # Assuming each entry is 4 bytes (function pointer size)
        vector_table_offsets[table_name] = offsets

    return vector_table_offsets

# Function to write combined output
def write_output(output_file, struct_offsets, vector_table_offsets):
    with open(output_file, 'w') as file:
        for struct_name, fields in struct_offsets.items():
            file.write(f'{struct_name}:\n')
            for field_name, offset in fields.items():
                file.write(f' {field_name} : {offset}\n')
            file.write('\n')
        
        # Write the vector table if found
        for table_name, entries in vector_table_offsets.items():
            file.write(f'{table_name} (Vector Table):\n')
            for entry_name, offset in entries.items():
                file.write(f' {entry_name} : {offset}\n')
            file.write('\n')

# Function to process input files
def process_files(input_files):
    all_struct_offsets = {}
    all_vector_table_offsets = {}

    for input_file in input_files:
        if os.path.isfile(input_file):
            with open(input_file, 'r') as file:
                content = file.read()
                struct_offsets = parse_header_file(input_file)
                vector_table_offsets = parse_vector_table(content)
                
                all_struct_offsets.update(struct_offsets)
                all_vector_table_offsets.update(vector_table_offsets)

    return all_struct_offsets, all_vector_table_offsets

# Main function
def main():
    parser = argparse.ArgumentParser(description='Extract struct field and vector table offsets from C header and source files.')
    parser.add_argument('input_files', nargs='+', help='Input files to parse (supports glob patterns).')
    parser.add_argument('-o', '--output', type=str, required=True, help='Output file to write the results.')

    args = parser.parse_args()
    
    input_files = []
    for pattern in args.input_files:
        input_files.extend(glob.glob(pattern))
    
    struct_offsets, vector_table_offsets = process_files(input_files)
    write_output(args.output, struct_offsets, vector_table_offsets)

if __name__ == '__main__':
    main()


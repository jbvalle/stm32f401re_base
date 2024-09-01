import struct

# List of configuration values (example values, can be changed as per requirement)
config_values = [
    0xFFFF1111,  # Config value 1
    0x00002222,  # Config value 2
    0xAAAA3333,  # Config value 3
    0xBBBB4444   # Config value 4
]

# Open a file to write the hex data
with open("gen/config/config_data.hex", "wb") as hex_file:
    for value in config_values:
        # Pack the integer into 4 bytes (little-endian format)
        hex_data = struct.pack("<I", value)
        # Write the packed data to the file
        hex_file.write(hex_data)

print("Configuration hex file generated successfully.")


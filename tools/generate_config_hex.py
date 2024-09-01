import struct
import os

# List of configuration values and their specific offsets
config_data = [
    (0xAAAA3333, 0x08),  # (Config value 3, Offset 0x08)
]

# Directory path
dir_path = "gen/config"

# Check if the directory exists, if not, create it
if not os.path.exists(dir_path):
    os.makedirs(dir_path)

# Open a file to write the hex data
with open(os.path.join(dir_path, "config_data.hex"), "wb") as hex_file:
    for value, offset in config_data:
        # Move the file pointer to the specified offset
        hex_file.seek(offset)
        # Pack the integer into 4 bytes (little-endian format)
        hex_data = struct.pack("<I", value)
        # Write the packed data to the file at the specific offset
        hex_file.write(hex_data)

print("Configuration hex file with specific offsets generated successfully.")


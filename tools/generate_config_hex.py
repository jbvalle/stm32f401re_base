import struct
import os

# List of configuration values (example values, can be changed as per requirement)
config_values = [
    0xFFFF1111,  # Config value 1
    0x00002222,  # Config value 2
    0xAAAA3333,  # Config value 3
    0xBBBB4444,  # Config value 4
    0xCCCC4444,  # Config value 4
    0xDDDD4444,  # Config value 4
    0xEEEE4444,  # Config value 4
]

# Directory path
dir_path = "gen/config"

# Check if the directory exists, if not, create it
if not os.path.exists(dir_path):
    os.makedirs(dir_path)

# Open a file to write the hex data
with open(os.path.join(dir_path, "config_data.hex"), "wb") as hex_file:
    for value in config_values:
        # Pack the integer into 4 bytes (little-endian format)
        hex_data = struct.pack("<I", value)
        # Write the packed data to the file
        hex_file.write(hex_data)

print("Configuration hex file generated successfully.")

#import struct
#
## List of configuration values (example values, can be changed as per requirement)
#config_values = [
#    0xFFFF1111,  # Config value 1
#    0x00002222,  # Config value 2
#    0xAAAA3333,  # Config value 3
#    0xBBBB4444   # Config value 4
#]
#
## Open a file to write the hex data
#with open("gen/config/config_data.hex", "wb") as hex_file:
#    for value in config_values:
#        # Pack the integer into 4 bytes (little-endian format)
#        hex_data = struct.pack("<I", value)
#        # Write the packed data to the file
#        hex_file.write(hex_data)
#
#print("Configuration hex file generated successfully.")
#

import os
from PIL import Image

image_path = 'src/assets/soloprojprofilepic.jpg'
out_header = 'ProfilePic.h'

# 1. Resize the image to save space
img = Image.open(image_path)
img.thumbnail((200, 200)) # Resize to max 200x200
img.save('resized_pic.jpg', quality=75)

# 2. Read the resized image as bytes
with open('resized_pic.jpg', 'rb') as f:
    img_data = f.read()

# 3. Convert to C array format
c_array = ', '.join([f'0x{b:02x}' for b in img_data])

# 4. Write to ProfilePic.h
with open(out_header, 'w') as f:
    f.write('#ifndef PROFILEPIC_H\n#define PROFILEPIC_H\n\n')
    f.write('#include <pgmspace.h>\n\n')
    f.write(f'const size_t profilePicLen = {len(img_data)};\n')
    f.write(f'const uint8_t profilePic[] PROGMEM = {{\n{c_array}\n}};\n\n')
    f.write('#endif\n')

print(f"Done. Resized image is {len(img_data)} bytes.")

import os

# Read WebPages.h
with open('WebPages.h', 'r', encoding='utf-8') as f:
    webpages_content = f.read()

# Read the INO file
with open('FINAL WORKING PROTOTYPE.INO', 'r', encoding='utf-8') as f:
    ino_lines = f.readlines()

# Write the combined file
with open('topasteinarduino.ino', 'w', encoding='utf-8') as f:
    for line in ino_lines:
        if line.strip() == '#include "WebPages.h"':
            f.write('// --- START OF EMBEDDED WEBPAGES ---\n')
            f.write(webpages_content)
            f.write('\n// --- END OF EMBEDDED WEBPAGES ---\n')
        else:
            f.write(line)

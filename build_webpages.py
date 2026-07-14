import os

html_files = {
    'PAGE_HERO': 'src/Software/Hero-page-screen1.html',
    'PAGE_ABOUT': 'src/Software/about.html',
    'PAGE_READINGS': 'src/Software/telemetry-dash-readings.html',
    'PAGE_GRAPHS': 'src/Software/telemetry-dash(graphs).html'
}

with open('WebPages.h', 'w', encoding='utf-8') as out:
    out.write('#ifndef WEBPAGES_H\n#define WEBPAGES_H\n\n')
    for var, path in html_files.items():
        with open(path, 'r', encoding='utf-8') as f:
            content = f.read()
            out.write(f'const char* {var} PROGMEM = R"rawliteral(\n{content}\n)rawliteral";\n\n')
    out.write('#endif\n')

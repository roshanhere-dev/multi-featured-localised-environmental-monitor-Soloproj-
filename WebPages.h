#ifndef WEBPAGES_H
#define WEBPAGES_H

const char* PAGE_HERO PROGMEM = R"rawliteral(
<!DOCTYPE html>

<html class="dark" lang="en" ><head>
<meta charset="utf-8"/>
<meta content="width=device-width, initial-scale=1.0" name="viewport"/>
<title>Roshan's Solo-Project - Terminal</title>
<script src="https://cdn.tailwindcss.com?plugins=forms,container-queries"></script>
<link href="https://fonts.googleapis.com/css2?family=Material+Symbols+Outlined:wght,FILL@100..700,0..1&amp;display=swap" rel="stylesheet"/>
<link href="https://fonts.googleapis.com/css2?family=Geist:wght@600;700&amp;family=Inter:wght@400&amp;family=JetBrains+Mono:wght@500;700&amp;display=swap" rel="stylesheet"/>
<script id="tailwind-config">
        tailwind.config = {
          darkMode: "class",
          theme: {
            extend: {
              "colors": {
                      "error": "#ffb4ab",
                      "tertiary-container": "#a0a3a5",
                      "surface-container-lowest": "#060e20",
                      "error-container": "#93000a",
                      "secondary-container": "#03b5d3",
                      "on-secondary-fixed": "#001f26",
                      "surface-variant": "#2d3449",
                      "surface-dim": "#0b1326",
                      "surface-container": "#171f33",
                      "on-secondary": "#003640",
                      "on-tertiary-container": "#36393b",
                      "on-primary-fixed-variant": "#005236",
                      "surface": "#0b1326",
                      "inverse-primary": "#006c49",
                      "on-error": "#690005",
                      "primary": "#4edea3",
                      "on-tertiary-fixed": "#191c1e",
                      "on-tertiary": "#2d3133",
                      "tertiary": "#c4c7c9",
                      "on-surface-variant": "#bbcabf",
                      "on-tertiary-fixed-variant": "#444749",
                      "on-secondary-fixed-variant": "#004e5c",
                      "outline": "#86948a",
                      "on-surface": "#dae2fd",
                      "on-primary-fixed": "#002113",
                      "primary-fixed": "#6ffbbe",
                      "secondary-fixed": "#acedff",
                      "on-error-container": "#ffdad6",
                      "on-primary-container": "#00422b",
                      "on-primary": "#003824",
                      "surface-bright": "#31394d",
                      "inverse-surface": "#dae2fd",
                      "tertiary-fixed": "#e0e3e5",
                      "secondary": "#4cd7f6",
                      "outline-variant": "#3c4a42",
                      "surface-tint": "#4edea3",
                      "surface-container-highest": "#2d3449",
                      "surface-container-high": "#222a3d",
                      "primary-fixed-dim": "#4edea3",
                      "secondary-fixed-dim": "#4cd7f6",
                      "on-secondary-container": "#00424e",
                      "on-background": "#dae2fd",
                      "surface-container-low": "#131b2e",
                      "tertiary-fixed-dim": "#c4c7c9",
                      "background": "#0b1326",
                      "inverse-on-surface": "#283044",
                      "primary-container": "#10b981"
              },
              "borderRadius": {
                      "DEFAULT": "0.125rem",
                      "lg": "0.25rem",
                      "xl": "0.5rem",
                      "full": "0.75rem"
              },
              "spacing": {
                      "container-max": "1440px",
                      "gutter": "24px",
                      "margin-mobile": "16px",
                      "margin-desktop": "40px",
                      "unit": "4px"
              },
              "fontFamily": {
                      "code-sm": [
                              "JetBrains Mono"
                      ],
                      "label-caps": [
                              "JetBrains Mono"
                      ],
                      "headline-lg-mobile": [
                              "Geist"
                      ],
                      "display-lg": [
                              "Geist"
                      ],
                      "headline-lg": [
                              "Geist"
                      ],
                      "body-md": [
                              "Inter"
                      ]
              },
              "fontSize": {
                      "code-sm": [
                              "14px",
                              {
                                      "lineHeight": "1.5",
                                      "fontWeight": "500"
                              }
                      ],
                      "label-caps": [
                              "12px",
                              {
                                      "lineHeight": "1",
                                      "letterSpacing": "0.1em",
                                      "fontWeight": "700"
                              }
                      ],
                      "headline-lg-mobile": [
                              "24px",
                              {
                                      "lineHeight": "1.2",
                                      "fontWeight": "600"
                              }
                      ],
                      "display-lg": [
                              "48px",
                              {
                                      "lineHeight": "1.1",
                                      "letterSpacing": "-0.02em",
                                      "fontWeight": "700"
                              }
                      ],
                      "headline-lg": [
                              "32px",
                              {
                                      "lineHeight": "1.2",
                                      "letterSpacing": "-0.01em",
                                      "fontWeight": "600"
                              }
                      ],
                      "body-md": [
                              "16px",
                              {
                                      "lineHeight": "1.6",
                                      "letterSpacing": "0",
                                      "fontWeight": "400"
                              }
                      ]
              }
            }
          }
        }
    </script>
<style>
        .glow-text {
            text-shadow: 0 0 20px rgba(78, 222, 163, 0.4);
        }
        @keyframes pulse-emerald {
            0% { box-shadow: 0 0 0 0 rgba(78, 222, 163, 0.7); }
            70% { box-shadow: 0 0 0 15px rgba(78, 222, 163, 0); }
            100% { box-shadow: 0 0 0 0 rgba(78, 222, 163, 0); }
        }
        .btn-pulse {
            animation: pulse-emerald 2s infinite;
        }
        .terminal-grid {
            background-image: 
                linear-gradient(rgba(255, 255, 255, 0.03) 1px, transparent 1px),
                linear-gradient(90deg, rgba(255, 255, 255, 0.03) 1px, transparent 1px);
            background-size: 24px 24px;
        }
        .custom-scrollbar::-webkit-scrollbar { width: 4px; }
        .custom-scrollbar::-webkit-scrollbar-track { background: transparent; }
        .custom-scrollbar::-webkit-scrollbar-thumb { background: #4edea3; }
    </style>
</head>
<body class="bg-background text-on-background font-body-md antialiased h-screen flex flex-col overflow-hidden selection:bg-primary selection:text-on-primary relative">
<!-- Abstract Ambient Glow Background -->
<div aria-hidden="true" class="absolute inset-0 pointer-events-none overflow-hidden">
<div class="absolute top-[-20%] left-[-10%] w-[50%] h-[50%] bg-primary/5 rounded-full blur-[120px]"></div>
<div class="absolute bottom-[-10%] right-[-10%] w-[40%] h-[40%] bg-secondary/5 rounded-full blur-[100px]"></div>
</div>
<!-- Shared Component: TopNavBar -->
<header class="w-full z-50 bg-surface/70 backdrop-blur-xl border-b border-white/10 shadow-none flex-shrink-0">
<div class="flex justify-between items-center px-margin-desktop py-2 max-w-container-max mx-auto">
<div class="font-display-lg text-display-lg font-bold text-primary tracking-tighter cursor-pointer active:scale-95"><span class="font-code-sm text-code-sm text-primary uppercase tracking-widest">Roshan Shorey</span></div>
<div class="font-code-sm text-[10px] sm:text-code-sm text-on-surface-variant uppercase tracking-widest opacity-80">2nd Year, SVNIT Surat</div></div>
</header>
<!-- Main Canvas -->
<main class="flex-grow flex flex-col items-center justify-center px-margin-mobile md:px-margin-desktop py-4 md:py-8 relative z-10 w-full max-w-container-max mx-auto overflow-hidden">
<!-- Header -->
<div class="text-center mb-6 max-w-4xl mx-auto flex-shrink-0 h-[100px] md:h-[110px] flex flex-col justify-end">
<h1 class="font-display-lg text-[40px] md:text-[56px] text-on-surface leading-[1.1] mb-2 tracking-tighter min-h-[44px] md:min-h-[61px]"><span class="text-primary glow-text block mt-1" id="welcome-text"></span>
</h1>
<p class="font-code-sm text-[12px] md:text-code-sm text-on-surface-variant max-w-2xl mx-auto opacity-80 uppercase tracking-widest min-h-[18px] md:min-h-[21px]" id="subtitle-text"></p>
</div>
<!-- Central Component: Terminal Window -->
<div class="w-full max-w-3xl bg-surface-container-lowest border border-white/10 rounded-none shadow-[0_0_30px_rgba(0,0,0,0.5)] mb-6 relative group terminal-grid flex flex-col flex-shrink">
<!-- Glassmorphic highlight border simulation -->
<div class="absolute top-0 left-0 w-full h-[1px] bg-gradient-to-r from-primary/30 to-transparent"></div>
<div class="absolute top-0 left-0 w-[1px] h-full bg-gradient-to-b from-primary/30 to-transparent"></div>
<!-- Terminal Header bar -->
<div class="flex items-center justify-between px-4 py-2 bg-surface-container/50 border-b border-white/5 flex-shrink-0">
<div class="flex gap-2">
<div class="w-3 h-3 rounded-full bg-surface-variant"></div>
<div class="w-3 h-3 rounded-full bg-surface-variant"></div>
<div class="w-3 h-3 rounded-full bg-surface-variant"></div>
</div>
<div class="font-code-sm text-[12px] text-on-surface-variant opacity-50">soloproj@roshanhere-dev</div>
<div class="w-12"></div> <!-- Spacer for center alignment -->
</div>
<!-- Terminal Content -->
<div class="p-4 md:p-6 font-code-sm text-[12px] md:text-code-sm text-on-surface-variant whitespace-pre-wrap leading-relaxed h-[200px] md:h-[250px] overflow-y-auto custom-scrollbar flex-grow" id="terminal-content"></div>
</div>
<!-- CTA Action -->
<div class="relative flex justify-center items-center h-12 flex-shrink-0 w-full max-w-sm mx-auto">
<div class="absolute font-label-caps text-label-caps text-on-surface-variant opacity-70 uppercase tracking-widest transition-opacity duration-500 flex items-center gap-2" id="wait-indicator">
<span class="animate-pulse">PLEASE WAIT...</span>
</div>

<button class="absolute bg-primary text-on-primary font-label-caps text-label-caps px-6 py-3 uppercase tracking-widest hover:bg-primary-fixed transition-all duration-700 btn-pulse flex items-center gap-3 opacity-0 scale-95 pointer-events-none" id="dashboard-btn" onclick="window.location.href='about.html';">
                <a href="about.html">Enter Monitor Dashboard !!</a>
                <span class="material-symbols-outlined text-[18px]">arrow_forward</span>        
</button>

</div>
</main>
<!-- Shared Component: Footer -->
<footer class="w-full bg-surface-dim/80 backdrop-blur-md border-t border-white/5 z-40 flex-shrink-0">
<div class="flex flex-col md:flex-row justify-between items-center px-margin-desktop py-3 w-full">
<div class="font-label-caps text-[10px] md:text-label-caps text-on-surface mb-2 md:mb-0">
                Designed &amp; Engineered by Roshan Shorey
            </div>
<div class="flex items-center gap-6">
<!-- Links from JSON -->
<a class="font-code-sm text-[12px] md:text-code-sm text-on-surface-variant hover:text-secondary-fixed-dim transition-all hover:opacity-80" href="https://github.com/roshanhere-dev" target="_blank">GitHub</a>
<a class="font-code-sm text-[12px] md:text-code-sm text-on-surface-variant hover:text-secondary-fixed-dim transition-all hover:opacity-80" href="https://in.linkedin.com/in/roshan-shorey-418248371" target="_blank">LinkedIn</a>
</div>
</div>
</footer>
<script>
    document.addEventListener("DOMContentLoaded", () => {
        const terminalData = [
            [
                { text: "> ", class: "text-secondary opacity-70" },
                { text: "[SYSTEM]", class: "text-secondary" },
                { text: " Initializing ESP32 microcontroller Core...\n", class: "" }
            ],
            [
                { text: "> ", class: "text-secondary opacity-70" },
                { text: "[I2C BUS]", class: "text-secondary-fixed" },
                { text: " BME280 climate sensor detected at address ", class: "" },
                { text: "0x76\n", class: "text-primary-fixed" }
            ],
            [
                { text: "> ", class: "text-secondary opacity-70" },
                { text: "[ANALOG]", class: "text-tertiary-container" },
                { text: " MQ135 gas tracking array... ", class: "" },
                { text: "CALIBRATED\n", class: "text-primary font-bold" }
            ],
            [
                { text: "> ", class: "text-secondary opacity-70" },
                { text: "[STATUS]", class: "text-inverse-surface" },
                { text: " WebSockets local server link... ", class: "" },
                { text: "STABLE\n", class: "text-primary font-bold" }
            ],
            [
                { text: "> ", class: "text-secondary opacity-70" },
                { text: "[NETWORK]", class: "text-secondary-fixed" },
                { text: " WiFi SSID 'IoT_Core_Secure' connected... ", class: "" },
                { text: "OK\n", class: "text-primary font-bold" }
            ]
        ];

        const welcomeText = document.getElementById('welcome-text');
        const subtitleText = document.getElementById('subtitle-text');
        const terminalContainer = document.getElementById('terminal-content');
        const dashboardBtn = document.getElementById('dashboard-btn');
        const waitIndicator = document.getElementById('wait-indicator');
        
        async function typeString(element, text, cursorChar, speed) {
            const cursor = document.createElement('span');
            cursor.textContent = cursorChar;
            cursor.className = 'animate-pulse font-bold opacity-70 ml-1';
            element.appendChild(cursor);
            
            for (let i = 0; i < text.length; i++) {
                const charNode = document.createTextNode(text[i]);
                element.insertBefore(charNode, cursor);
                await new Promise(r => setTimeout(r, speed));
            }
            cursor.remove();
        }

        async function runSequence() {
            await new Promise(r => setTimeout(r, 600)); // Initial delay
            
            // 1. Type Welcome
            await typeString(welcomeText, "Welcome !!", "|", 70);
            
            await new Promise(r => setTimeout(r, 400));
            
            // 2. Type Subtitle
            await typeString(subtitleText, "A multi-featured LOCALISED ENVIRONMENTAL Monitor\u00A0", "|", 30);
            
            await new Promise(r => setTimeout(r, 500));
            
            // 3. Terminal Logs
            let currentCursor = document.createElement('span');
            currentCursor.className = 'animate-pulse text-primary font-bold';
            currentCursor.textContent = '_';
            terminalContainer.appendChild(currentCursor);

            for (let i = 0; i < terminalData.length; i++) {
                const lineData = terminalData[i];
                
                for (let j = 0; j < lineData.length; j++) {
                    const segment = lineData[j];
                    const span = document.createElement('span');
                    if (segment.class) span.className = segment.class;
                    
                    terminalContainer.insertBefore(span, currentCursor);
                    
                    for (let k = 0; k < segment.text.length; k++) {
                        span.textContent += segment.text[k];
                        terminalContainer.scrollTop = terminalContainer.scrollHeight;
                        await new Promise(r => setTimeout(r, 20)); // Typing speed
                    }
                }
                await new Promise(r => setTimeout(r, 400)); // Delay between lines
            }
            
            // Wait before revealing button
            await new Promise(r => setTimeout(r, 600));
            
            // 4 & 5. Transition Button
            waitIndicator.classList.add('opacity-0');
            setTimeout(() => {
                waitIndicator.style.display = 'none';
                dashboardBtn.classList.remove('opacity-0', 'scale-95', 'pointer-events-none');
                dashboardBtn.classList.add('opacity-100', 'scale-100');
            }, 500);
        }

        runSequence();
    });
</script>
</body>
</html>
)rawliteral";

const char* PAGE_ABOUT PROGMEM = R"rawliteral(
<!DOCTYPE html>

<html class="dark" lang="en"><head>
<meta charset="utf-8"/>
<meta content="width=device-width, initial-scale=1.0" name="viewport"/>
<link href="https://fonts.googleapis.com/css2?family=Inter:wght@400;500;600;700&amp;family=JetBrains+Mono:wght@500;600&amp;display=swap" rel="stylesheet"/>
<link href="https://fonts.googleapis.com/css2?family=Material+Symbols+Outlined:wght,FILL@100..700,0..1&amp;display=block" rel="stylesheet"/>
<script src="https://cdn.tailwindcss.com?plugins=forms,container-queries"></script>
<script id="tailwind-config">
        try {
            tailwind.config = {
                darkMode: "class",
                theme: {
                    extend: {
                        "colors": {
                            "on-secondary-container": "#0c714d",
                            "background": "#0b1c30",
                            "inverse-primary": "#b3c5ff",
                            "surface-tint": "#1155d0",
                            "surface-bright": "#f8f9ff",
                            "on-tertiary-container": "#fff7f1",
                            "surface-container-low": "#112236",
                            "on-primary-fixed": "#001849",
                            "aqi-excellent": "#6cf8bb",
                            "on-primary-fixed-variant": "#003fa4",
                            "secondary": "#6cf8bb",
                            "inverse-on-surface": "#eaf1ff",
                            "on-error": "#ffffff",
                            "on-tertiary-fixed-variant": "#653e00",
                            "secondary-fixed-dim": "#81d8ad",
                            "on-surface": "#ffffff",
                            "primary-fixed": "#dae1ff",
                            "on-error-container": "#93000a",
                            "primary-fixed-dim": "#b3c5ff",
                            "on-secondary-fixed": "#002113",
                            "on-primary-container": "#f8f7ff",
                            "on-surface-variant": "#c2c6d8",
                            "primary": "#b3c5ff",
                            "on-secondary": "#000000",
                            "outline": "#727687",
                            "tertiary-fixed": "#ffddb8",
                            "on-secondary-fixed-variant": "#005236",
                            "surface-variant": "#213145",
                            "error-container": "#ffdad6",
                            "tertiary": "#fcba68",
                            "outline-variant": "#424656",
                            "secondary-container": "#006c49",
                            "surface-container-high": "#1e2f47",
                            "primary-container": "#1155d0",
                            "inverse-surface": "#eaf1ff",
                            "on-primary": "#001849",
                            "on-tertiary-fixed": "#2a1700",
                            "on-background": "#ffffff",
                            "secondary-fixed": "#9df4c8",
                            "on-tertiary": "#000000",
                            "tertiary-fixed-dim": "#fcba68",
                            "tertiary-container": "#9b671c",
                            "surface-dim": "#0b1c30",
                            "error": "#ffb4ab",
                            "surface-container": "#112236",
                            "surface": "#0b1c30",
                            "surface-container-highest": "#213145",
                            "surface-container-lowest": "#071321"
                        },
                        "borderRadius": {
                            "DEFAULT": "1rem",
                            "lg": "2rem",
                            "xl": "3rem",
                            "full": "9999px"
                        },
                        "spacing": {
                            "margin-mobile": "16px",
                            "card-padding": "2rem",
                            "margin-desktop": "40px",
                            "gutter": "24px",
                            "unit": "4px",
                            "container-max-width": "1440px"
                        },
                        "fontFamily": {
                            "label-sm": ["JetBrains Mono"],
                            "headline-lg": ["Inter"],
                            "headline-md": ["Inter"],
                            "display-lg": ["Inter"],
                            "body-lg": ["Inter"],
                            "headline-lg-mobile": ["Inter"],
                            "body-md": ["Inter"],
                            "data-display": ["JetBrains Mono"]
                        },
                        "fontSize": {
                            "label-sm": ["12px", { "lineHeight": "16px", "letterSpacing": "0.05em", "fontWeight": "600" }],
                            "headline-lg": ["32px", { "lineHeight": "40px", "letterSpacing": "-0.01em", "fontWeight": "600" }],
                            "headline-md": ["24px", { "lineHeight": "32px", "fontWeight": "600" }],
                            "display-lg": ["48px", { "lineHeight": "56px", "letterSpacing": "-0.02em", "fontWeight": "700" }],
                            "body-lg": ["18px", { "lineHeight": "28px", "fontWeight": "400" }],
                            "headline-lg-mobile": ["24px", { "lineHeight": "32px", "fontWeight": "600" }],
                            "body-md": ["16px", { "lineHeight": "24px", "fontWeight": "400" }],
                            "data-display": ["20px", { "lineHeight": "24px", "fontWeight": "500" }]
                        }
                    },
                },
            }
        } catch (_e) {}
    </script>
<style>
        .glass-card {
            background: rgba(17, 34, 54, 0.6);
            backdrop-filter: blur(12px);
            border: 1px solid rgba(255, 255, 255, 0.05);
        }
    </style>
</head>
<body class="bg-surface-dim min-h-screen text-on-surface selection:bg-primary-container selection:text-white">
<!-- TopAppBar -->
<header class="bg-surface-container-lowest/80 backdrop-blur-xl border-b border-white/5 flex justify-between items-center px-margin-desktop w-full h-16 z-40 fixed top-0 left-0">
<div class="flex items-center gap-4">
<button aria-label="Open navigation" class="material-symbols-outlined text-on-surface-variant hover:text-primary p-2 rounded-full transition-colors lg:hidden" id="hamburger-btn" onclick="openDrawer()">menu</button>
<span class="font-headline-md text-headline-md font-bold text-primary">EcoPulse IoT</span>
</div>
<div class="flex items-center gap-6">
<div class="hidden md:flex gap-6">
<button class="font-headline-md text-headline-md font-bold text-primary transition-opacity hover:opacity-80">Dashboard</button>
</div>
<div class="flex gap-4">
<button class="material-symbols-outlined text-on-surface-variant hover:text-primary p-2 rounded-full transition-colors">sensors</button>
<button class="material-symbols-outlined text-on-surface-variant hover:text-primary p-2 rounded-full transition-colors">wifi</button>
<button class="material-symbols-outlined text-on-surface-variant hover:text-primary p-2 rounded-full transition-colors">schedule</button>
</div>
</div>
</header>
<!-- Backdrop overlay (mobile) -->
<div class="fixed inset-0 bg-black/60 backdrop-blur-sm z-40 hidden transition-opacity duration-300" id="drawer-overlay" onclick="closeDrawer()"></div>
<!-- SideNavBar -->
<aside class="fixed left-0 top-0 h-full flex flex-col p-6 z-50 bg-surface-container-lowest/95 backdrop-blur-xl border-r border-white/5
  -translate-x-full lg:translate-x-0 transition-transform duration-300 ease-in-out" id="side-nav" style="width:18rem">
<div class="flex items-center justify-between mb-10 pt-4 lg:pt-16">
<div>
<h1 class="font-headline-md text-headline-md font-bold text-primary mb-1">Environmental Monitor</h1>
<p class="font-body-md text-body-md text-on-surface-variant">Solo Project</p>
</div>
<button aria-label="Close navigation" class="material-symbols-outlined text-on-surface-variant hover:text-primary p-1 rounded-full transition-colors lg:hidden" onclick="closeDrawer()">close</button>
</div>
<nav class="flex-1 space-y-2">
<a class="flex items-center gap-4 p-4 bg-primary/10 text-primary font-bold rounded-xl active:scale-95 duration-200 border border-primary/20" href="#">
<span class="material-symbols-outlined">info</span>
<span class="font-body-md text-body-md">About</span>
</a>
<a class="flex items-center gap-4 p-4 text-on-surface-variant hover:bg-white/5 hover:text-white transition-all rounded-xl active:scale-95 duration-200" href="telemetry-dash-readings.html">
<span class="material-symbols-outlined">dashboard</span>
<span class="font-body-md text-body-md">Readings</span>
</a>
<a class="flex items-center gap-4 p-4 text-on-surface-variant hover:bg-white/5 hover:text-white transition-all rounded-xl active:scale-95 duration-200" href="telemetry-dash(graphs).html">
<span class="material-symbols-outlined">analytics</span>
<span class="font-body-md text-body-md">Graphs</span>
</a>
</nav>
<div class="mt-auto space-y-6">
<a href="https://github.com/" target="_blank"><button class="w-full bg-primary text-on-primary py-3 rounded-xl font-bold hover:bg-primary/90 transition-all active:scale-95">Github Repo</button></a>
<div class="flex items-center gap-3">
<div class="w-10 h-10 rounded-full bg-surface-variant overflow-hidden border border-white/10 flex-shrink-0">
<img alt="Roshan Shorey" class="w-full h-full object-cover brightness-110" src="../assets/soloprojprofilepic.jpg"/>
</div>
<div>
<a href="https://www.linkedin.com/in/roshan-shorey-418248371/" target="_blank"><p class="font-body-md text-body-md font-bold text-on-surface">Roshan Shorey</p></a>
<div class="font-label-sm text-label-sm text-on-surface-variant">2nd Year, SVNIT Surat</div>
</div>
</div>
</div>
</aside>
<!-- Main Content -->
<main class="pt-24 pb-16 px-margin-mobile lg:pl-72 lg:pr-margin-desktop min-h-screen">

  <!-- Hero Header -->
  <div class="mb-12">
    <div class="flex items-center gap-3 mb-3">
      <span class="material-symbols-outlined text-secondary text-3xl">sensors</span>
      <span class="font-label-sm text-label-sm text-secondary uppercase tracking-widest">Solo IoT Project</span>
    </div>
    <h2 class="font-headline-lg text-headline-lg text-on-surface mb-4">ESP32 Smart Environmental Dashboard</h2>
    <p class="font-body-lg text-body-lg text-on-surface-variant max-w-3xl">An advanced, IoT-enabled environmental telemetry station built on the ESP32 microcontroller. Integrates the BME280 Climate Sensor, MQ135 Gas Sensor (with localized baseline calibration), and an LM393 Rain Sensor to serve an interactive, live web dashboard with real-time data visualization and side-by-side localized comparison analytics against official municipal meteorological data.</p>
  </div>

  <!-- Key Features -->
  <section class="mb-12">
    <h3 class="font-headline-md text-headline-md text-on-surface mb-6 flex items-center gap-3">
      <span class="material-symbols-outlined text-primary">rocket_launch</span> Key Features
    </h3>
    <div class="grid grid-cols-1 md:grid-cols-2 gap-5">
      <div class="glass-card rounded-2xl p-6 flex gap-4 items-start">
        <div class="w-10 h-10 rounded-xl bg-primary/10 flex items-center justify-center flex-shrink-0">
          <span class="material-symbols-outlined text-primary text-xl">compare_arrows</span>
        </div>
        <div>
          <p class="font-body-md font-bold text-on-surface mb-1">Micro-Local vs. Macro-Metro Comparison API</p>
          <p class="font-label-sm text-label-sm text-on-surface-variant">Automatically fetches official real-time meteorological data for Kalyan from public APIs (OpenWeatherMap / WAQI) and displays it side-by-side with your physical breadboard telemetry.</p>
        </div>
      </div>
      <div class="glass-card rounded-2xl p-6 flex gap-4 items-start">
        <div class="w-10 h-10 rounded-xl bg-secondary/10 flex items-center justify-center flex-shrink-0">
          <span class="material-symbols-outlined text-secondary text-xl">show_chart</span>
        </div>
        <div>
          <p class="font-body-md font-bold text-on-surface mb-1">Dynamic Real-Time Charts &amp; Graphs</p>
          <p class="font-label-sm text-label-sm text-on-surface-variant">Diversified line charts, trend vectors, and dynamic radial gauges visualize localized telemetry trends natively inside the browser, updating asynchronously via WebSockets or Server-Sent Events.</p>
        </div>
      </div>
      <div class="glass-card rounded-2xl p-6 flex gap-4 items-start">
        <div class="w-10 h-10 rounded-xl bg-tertiary/10 flex items-center justify-center flex-shrink-0">
          <span class="material-symbols-outlined text-tertiary text-xl">thermostat</span>
        </div>
        <div>
          <p class="font-body-md font-bold text-on-surface mb-1">High-Accuracy BME280 Micro-Climate Profiling</p>
          <p class="font-label-sm text-label-sm text-on-surface-variant">Collects highly accurate temperature, relative humidity, and local barometric pressure over the digital I&#178;C protocol using three distinct micromachined sensing elements.</p>
        </div>
      </div>
      <div class="glass-card rounded-2xl p-6 flex gap-4 items-start">
        <div class="w-10 h-10 rounded-xl bg-primary/10 flex items-center justify-center flex-shrink-0">
          <span class="material-symbols-outlined text-primary text-xl">air</span>
        </div>
        <div>
          <p class="font-body-md font-bold text-on-surface mb-1">Logarithmic AQI Estimation</p>
          <p class="font-label-sm text-label-sm text-on-surface-variant">Converts raw analog values from the MQ135 into a scaled Air Quality Index based on localized city baselines (Kalyan = 97), bypassing non-linear curve limitations of raw metal-oxide resistance.</p>
        </div>
      </div>
      <div class="glass-card rounded-2xl p-6 flex gap-4 items-start">
        <div class="w-10 h-10 rounded-xl bg-secondary/10 flex items-center justify-center flex-shrink-0">
          <span class="material-symbols-outlined text-secondary text-xl">rainy</span>
        </div>
        <div>
          <p class="font-body-md font-bold text-on-surface mb-1">Interactive Rain Telemetry</p>
          <p class="font-label-sm text-label-sm text-on-surface-variant">Maps real-time soil/precipitation conductivity from the LM393 probe, scaling precipitation levels from dry to torrential downpours in real time.</p>
        </div>
      </div>
      <div class="glass-card rounded-2xl p-6 flex gap-4 items-start">
        <div class="w-10 h-10 rounded-xl bg-tertiary/10 flex items-center justify-center flex-shrink-0">
          <span class="material-symbols-outlined text-tertiary text-xl">electric_bolt</span>
        </div>
        <div>
          <p class="font-body-md font-bold text-on-surface mb-1">Safe Electrical Topology</p>
          <p class="font-label-sm text-label-sm text-on-surface-variant">Series voltage divider protects the ESP32's 3.3&#8239;V ADC from the MQ135's native 5&#8239;V signaling. PWM drives physical hazard-alert LEDs with high-frequency blink alarms.</p>
        </div>
      </div>
    </div>
  </section>

  <!-- Sensor Science -->
  <section class="mb-12">
    <h3 class="font-headline-md text-headline-md text-on-surface mb-6 flex items-center gap-3">
      <span class="material-symbols-outlined text-secondary">biotech</span> Sensor Science &amp; Principles of Operation
    </h3>
    <p class="font-body-md text-on-surface-variant mb-6">The system merges three completely different physical and chemical sensing methodologies into a unified data structure.</p>
    <div class="space-y-5">
      <div class="glass-card rounded-2xl p-6">
        <div class="flex items-center gap-3 mb-4">
          <div class="w-9 h-9 rounded-xl bg-primary/10 flex items-center justify-center flex-shrink-0">
            <span class="material-symbols-outlined text-primary text-lg">device_thermostat</span>
          </div>
          <p class="font-body-md font-bold text-on-surface">1. The BME280 Climate Sensor (I&#178;C Digital)</p>
        </div>
        <div class="grid grid-cols-1 sm:grid-cols-3 gap-4">
          <div class="bg-white/3 rounded-xl p-4 border border-white/5">
            <p class="font-label-sm text-label-sm text-primary uppercase tracking-widest mb-2">Relative Humidity</p>
            <p class="font-label-sm text-label-sm text-on-surface-variant">Capacitive polymer dielectric layer — moisture alters capacitance proportionally: <span class="text-primary font-bold">C &#8733; &#949;&#7523;</span></p>
          </div>
          <div class="bg-white/3 rounded-xl p-4 border border-white/5">
            <p class="font-label-sm text-label-sm text-secondary uppercase tracking-widest mb-2">Barometric Pressure</p>
            <p class="font-label-sm text-label-sm text-on-surface-variant">Piezoresistive silicon diaphragm — mechanical deflection from atmospheric pressure alters integrated resistor values.</p>
          </div>
          <div class="bg-white/3 rounded-xl p-4 border border-white/5">
            <p class="font-label-sm text-label-sm text-tertiary uppercase tracking-widest mb-2">Temperature</p>
            <p class="font-label-sm text-label-sm text-on-surface-variant">Bandgap diode reference — forward voltage (V<sub>be</sub>) across silicon junction changes linearly: <span class="text-tertiary font-bold">&#916;V<sub>be</sub> &#8733; T</span></p>
          </div>
        </div>
      </div>
      <div class="glass-card rounded-2xl p-6">
        <div class="flex items-center gap-3 mb-4">
          <div class="w-9 h-9 rounded-xl bg-secondary/10 flex items-center justify-center flex-shrink-0">
            <span class="material-symbols-outlined text-secondary text-lg">air</span>
          </div>
          <p class="font-body-md font-bold text-on-surface">2. The MQ135 Air Quality Sensor (Heated SnO&#8322; Semiconductor)</p>
        </div>
        <div class="grid grid-cols-1 sm:grid-cols-2 gap-4 mb-4">
          <div class="bg-white/3 rounded-xl p-4 border border-white/5">
            <p class="font-label-sm text-label-sm text-secondary uppercase tracking-widest mb-2">In Clean Air</p>
            <p class="font-label-sm text-label-sm text-on-surface-variant">Oxygen molecules trap free electrons on SnO&#8322; crystal boundaries, forming an electrostatic barrier — internal resistance stays extremely high.</p>
          </div>
          <div class="bg-white/3 rounded-xl p-4 border border-white/5">
            <p class="font-label-sm text-label-sm text-tertiary uppercase tracking-widest mb-2">In Polluted Air</p>
            <p class="font-label-sm text-label-sm text-on-surface-variant">Reducing gases (NH&#8323;, NO&#8339;, CO&#8322;, VOCs) react with adsorbed oxygen &#8594; electrons released &#8594; sharp resistance drop: <span class="text-secondary font-bold">Rs &#8733; 1/[Gas]</span></p>
          </div>
        </div>
        <div class="bg-primary/5 border border-primary/15 rounded-xl p-4">
          <p class="font-label-sm text-label-sm text-primary uppercase tracking-widest mb-2">Calibration Anchor Formula (Kalyan Municipal AQI Baseline = 97)</p>
          <code class="font-label-sm text-label-sm text-secondary block bg-black/20 px-4 py-2 rounded-lg mb-2">Multiplier = Local Municipal AQI (97) &#247; Steady-State Raw ADC Reading</code>
          <code class="font-label-sm text-label-sm text-primary block bg-black/20 px-4 py-2 rounded-lg">Calculated AQI = Raw ADC Value &#215; Multiplier</code>
        </div>
      </div>
    </div>
  </section>

  <!-- Hardware Wiring -->
  <section class="mb-12">
    <h3 class="font-headline-md text-headline-md text-on-surface mb-6 flex items-center gap-3">
      <span class="material-symbols-outlined text-tertiary">settings_input_component</span> Hardware Architecture &amp; Wiring
    </h3>
    <div class="grid grid-cols-1 lg:grid-cols-2 gap-5">
      <div class="glass-card rounded-2xl p-6">
        <p class="font-label-sm text-label-sm text-tertiary uppercase tracking-widest mb-4">MQ135 — Analog Voltage Divider (5V &#8594; 3.3V ADC Safe)</p>
        <pre class="font-label-sm text-label-sm text-on-surface-variant bg-black/30 rounded-xl p-4 overflow-x-auto leading-relaxed border border-white/5">ESP32                      MQ135
&#9472;&#9472;&#9472;&#9472;&#9472;                      &#9472;&#9472;&#9472;&#9472;&#9472;
VIN (5V USB) &#9644;&#9644;&#9644;&#9644;&#9644;&#9644;&#9644;&#9644;&#9644;&#9644;&#9644;&#9644;&#9644;&#9654; VCC (5V)
GND &#9644;&#9644;&#9644;&#9644;&#9644;&#9644;&#9644;&#9644;&#9644;&#9644;&#9644;&#9644;&#9644;&#9644;&#9644;&#9644;&#9644;&#9644;&#9644;&#9644;&#9644;&#9654; GND

              AO Out &#9658;&#9658; [Row A]
                             &#9474;
                        [1k&#937; R1]
                             &#9474;
GPIO 34 (ADC) &#9668;&#9668;&#9668;&#9668; [Row B]
                             &#9474;
                        [1k&#937; R2 + R3]
                             &#9474;
GND &#9668;&#9668;&#9668;&#9668;&#9668;&#9668;&#9668;&#9668;&#9668;&#9668;&#9668;&#9668;&#9668;&#9668; [Row C &#9658; GND Rail]</pre>
      </div>
      <div class="glass-card rounded-2xl p-6">
        <p class="font-label-sm text-label-sm text-primary uppercase tracking-widest mb-4">BME280 — Digital I&#178;C (3.3V Native) + Rain Sensor</p>
        <pre class="font-label-sm text-label-sm text-on-surface-variant bg-black/30 rounded-xl p-4 overflow-x-auto leading-relaxed border border-white/5">ESP32                      BME280
&#9472;&#9472;&#9472;&#9472;&#9472;                      &#9472;&#9472;&#9472;&#9472;&#9472;&#9472;
3V3 (3.3V) &#9644;&#9644;&#9644;&#9644;&#9644;&#9644;&#9644;&#9644;&#9644;&#9644;&#9644;&#9644;&#9644;&#9644;&#9644;&#9654; VCC
GND &#9644;&#9644;&#9644;&#9644;&#9644;&#9644;&#9644;&#9644;&#9644;&#9644;&#9644;&#9644;&#9644;&#9644;&#9644;&#9644;&#9644;&#9644;&#9644;&#9644;&#9644;&#9654; GND
GPIO 21 (SDA) &#9644;&#9644;&#9644;&#9644;&#9644;&#9644;&#9644;&#9644;&#9644;&#9644;&#9644;&#9654; SDA
GPIO 22 (SCL) &#9644;&#9644;&#9644;&#9644;&#9644;&#9644;&#9644;&#9644;&#9644;&#9644;&#9644;&#9654; SCL

[LM393 Rain Sensor]
GPIO (ADC) &#9668;&#9668;&#9668;&#9668;&#9668;&#9668; AO (Analog Out)
VCC (3.3V) &#9654;&#9654;&#9654;&#9654;&#9654;&#9654; VCC
GND &#9654;&#9654;&#9654;&#9654;&#9654;&#9654;&#9654;&#9654;&#9654;&#9654;&#9654; GND</pre>
      </div>
    </div>
  </section>

  <!-- Data Flow -->
  <section class="mb-12">
    <h3 class="font-headline-md text-headline-md text-on-surface mb-6 flex items-center gap-3">
      <span class="material-symbols-outlined text-primary">account_tree</span> Live Web Interface &amp; Data Flow Topology
    </h3>
    <div class="glass-card rounded-2xl p-6 mb-5">
      <pre class="font-label-sm text-label-sm text-on-surface-variant bg-black/30 rounded-xl p-5 overflow-x-auto leading-loose border border-white/5">&#9484;&#9472;&#9472;&#9472;&#9472;&#9472;&#9472;&#9472;&#9472;&#9472;&#9472;&#9472;&#9472;&#9472;&#9472;&#9488;  I&#178;C (Digital)    &#9484;&#9472;&#9472;&#9472;&#9472;&#9472;&#9472;&#9472;&#9472;&#9472;&#9472;&#9472;&#9472;&#9472;&#9472;&#9472;&#9472;&#9472;&#9488;
&#9474; BME280 Sensor  &#9474; &#9472;&#9472;&#9472;&#9472;&#9472;&#9472;&#9472;&#9472;&#9472;&#9472;&#9472;&#9472;&#9472;&#9654; &#9474;                 &#9474;
&#9492;&#9472;&#9472;&#9472;&#9472;&#9472;&#9472;&#9472;&#9472;&#9472;&#9472;&#9472;&#9472;&#9472;&#9472;&#9496;                  &#9474;   ESP32           &#9474;
&#9484;&#9472;&#9472;&#9472;&#9472;&#9472;&#9472;&#9472;&#9472;&#9472;&#9472;&#9472;&#9472;&#9472;&#9472;&#9488;  Analog 0&#9472;3.3V  &#9474;   Micro-Server    &#9474;
&#9474; MQ135 (div.)  &#9474; &#9472;&#9472;&#9472;&#9472;&#9472;&#9472;&#9472;&#9472;&#9472;&#9472;&#9472;&#9472;&#9472;&#9654; &#9474;                 &#9474;
&#9492;&#9472;&#9472;&#9472;&#9472;&#9472;&#9472;&#9472;&#9472;&#9472;&#9472;&#9472;&#9472;&#9472;&#9472;&#9496;                  &#9474;                 &#9474;
&#9484;&#9472;&#9472;&#9472;&#9472;&#9472;&#9472;&#9472;&#9472;&#9472;&#9472;&#9472;&#9472;&#9472;&#9472;&#9488;  Analog 0&#9472;3.3V  &#9474;                 &#9474;
&#9474; Rain Sensor   &#9474; &#9472;&#9472;&#9472;&#9472;&#9472;&#9472;&#9472;&#9472;&#9472;&#9472;&#9472;&#9472;&#9472;&#9654; &#9474;                 &#9474;
&#9492;&#9472;&#9472;&#9472;&#9472;&#9472;&#9472;&#9472;&#9472;&#9472;&#9472;&#9472;&#9472;&#9472;&#9472;&#9496;                  &#9492;&#9472;&#9472;&#9472;&#9472;&#9472;&#9472;&#9472;&#9472;&#9472;&#9472;&#9472;&#9472;&#9472;&#9472;&#9472;&#9472;&#9472;&#9496;
                                           &#9474;
                                    Wi-Fi / WebSockets
                                           &#8595;
&#9484;&#9472;&#9472;&#9472;&#9472;&#9472;&#9472;&#9472;&#9472;&#9472;&#9472;&#9472;&#9472;&#9472;&#9472;&#9488;                  &#9484;&#9472;&#9472;&#9472;&#9472;&#9472;&#9472;&#9472;&#9472;&#9472;&#9472;&#9472;&#9472;&#9472;&#9472;&#9472;&#9472;&#9472;&#9488;
&#9474; Public Cloud  &#9474;                  &#9474;  Web Browser   &#9474;
&#9474; Weather API   &#9474; &#9668;&#9472;&#9472;&#9472;&#9472;&#9472;&#9472;&#9472;&#9472;&#9472;&#9472;&#9472;&#9472;&#9472;&#9472; &#9474;  Client Portal  &#9474;
&#9474; Metro Base.   &#9474;  JSON fetch(GET) &#9474;  (Live Charts)  &#9474;
&#9492;&#9472;&#9472;&#9472;&#9472;&#9472;&#9472;&#9472;&#9472;&#9472;&#9472;&#9472;&#9472;&#9472;&#9472;&#9496;                  &#9492;&#9472;&#9472;&#9472;&#9472;&#9472;&#9472;&#9472;&#9472;&#9472;&#9472;&#9472;&#9472;&#9472;&#9472;&#9472;&#9472;&#9472;&#9496;</pre>
    </div>
    <div class="grid grid-cols-1 sm:grid-cols-3 gap-4">
      <div class="glass-card rounded-xl p-5 border-t-2 border-primary/40">
        <span class="material-symbols-outlined text-primary mb-3 block">code</span>
        <p class="font-body-md font-bold text-on-surface mb-1">Frontend Technology</p>
        <p class="font-label-sm text-label-sm text-on-surface-variant">CSS Grid, SVG gauges, and Chart.js / HTML5 Canvas for lightweight real-time plotting in the browser.</p>
      </div>
      <div class="glass-card rounded-xl p-5 border-t-2 border-secondary/40">
        <span class="material-symbols-outlined text-secondary mb-3 block">sync</span>
        <p class="font-body-md font-bold text-on-surface mb-1">Asynchronous Telemetry</p>
        <p class="font-label-sm text-label-sm text-on-surface-variant">Telemetry parsed as structured JSON payloads over WebSocket/SSE &#8212; no page-reloads, no sensor lag.</p>
      </div>
      <div class="glass-card rounded-xl p-5 border-t-2 border-tertiary/40">
        <span class="material-symbols-outlined text-tertiary mb-3 block">cloud_download</span>
        <p class="font-body-md font-bold text-on-surface mb-1">Client-Side Comparison API</p>
        <p class="font-label-sm text-label-sm text-on-surface-variant">fetch() runs in the browser &#8212; regional meteorology pulled from cloud API without adding load to the ESP32.</p>
      </div>
    </div>
  </section>

  <!-- Repo Structure + Getting Started -->
  <div class="grid grid-cols-1 lg:grid-cols-2 gap-6 mb-4">
    <section>
      <h3 class="font-headline-md text-headline-md text-on-surface mb-5 flex items-center gap-3">
        <span class="material-symbols-outlined text-secondary">folder_open</span> Repository Structure
      </h3>
      <div class="glass-card rounded-2xl p-6">
        <pre class="font-label-sm text-label-sm text-on-surface-variant leading-loose"><span class="text-primary">src/</span>
  <span class="text-secondary">main_system/</span>         # Production unified code
    &#9492; main_system.ino
  <span class="text-secondary">prototypes/</span>          # Isolated unit tests
    &#9500; led_pwm_demo/      # Hardware PWM
    &#9500; bme280_i2c_test/   # I&#178;C scanning
    &#9500; rain_sensor_analog/ # Moisture mapping
    &#9492; mq135_calibrated/  # Localized multiplier
<span class="text-tertiary">docs/</span>                # Sensor guides, wiring, datasheets
README.md</pre>
      </div>
    </section>
    <section>
      <h3 class="font-headline-md text-headline-md text-on-surface mb-5 flex items-center gap-3">
        <span class="material-symbols-outlined text-primary">terminal</span> Installation &amp; Getting Started
      </h3>
      <div class="space-y-3">
        <div class="glass-card rounded-xl p-4 flex gap-4 items-start">
          <span class="w-6 h-6 rounded-full bg-primary/20 text-primary font-bold text-xs flex items-center justify-center flex-shrink-0 mt-0.5">1</span>
          <div>
            <p class="font-body-md font-bold text-on-surface mb-1">Clone the Repository</p>
            <code class="font-label-sm text-label-sm text-secondary bg-black/30 px-3 py-1.5 rounded-lg block break-all">git clone https://github.com/yourusername/esp32-environmental-dashboard.git</code>
          </div>
        </div>
        <div class="glass-card rounded-xl p-4 flex gap-4 items-start">
          <span class="w-6 h-6 rounded-full bg-primary/20 text-primary font-bold text-xs flex items-center justify-center flex-shrink-0 mt-0.5">2</span>
          <div>
            <p class="font-body-md font-bold text-on-surface mb-1">Open the Sketch</p>
            <p class="font-label-sm text-label-sm text-on-surface-variant">Load <code class="text-primary">src/main_system/main_system.ino</code> in Arduino IDE.</p>
          </div>
        </div>
        <div class="glass-card rounded-xl p-4 flex gap-4 items-start">
          <span class="w-6 h-6 rounded-full bg-primary/20 text-primary font-bold text-xs flex items-center justify-center flex-shrink-0 mt-0.5">3</span>
          <div>
            <p class="font-body-md font-bold text-on-surface mb-1">Install Board Package &amp; Libraries</p>
            <p class="font-label-sm text-label-sm text-on-surface-variant">Install ESP32 board manager + <span class="text-primary">Adafruit BME280 Library</span> via Arduino Library Manager.</p>
          </div>
        </div>
        <div class="glass-card rounded-xl p-4 flex gap-4 items-start">
          <span class="w-6 h-6 rounded-full bg-primary/20 text-primary font-bold text-xs flex items-center justify-center flex-shrink-0 mt-0.5">4</span>
          <div>
            <p class="font-body-md font-bold text-on-surface mb-1">Configure Wi-Fi &amp; Calibrate MQ135</p>
            <p class="font-label-sm text-label-sm text-on-surface-variant">Update SSID/Password in source. Pre-heat MQ135 for <span class="text-secondary font-bold">&#8805;5 min</span>, note the Serial Monitor raw ADC value, then set <code class="text-primary">MY_RAW_READING</code> to anchor the municipal-scaling algorithm.</p>
          </div>
        </div>
      </div>
    </section>
  </div>

</main>
<script>
function openDrawer(){
  document.getElementById('side-nav').classList.remove('-translate-x-full');
  document.getElementById('drawer-overlay').classList.remove('hidden');
  document.body.style.overflow='hidden';
}
function closeDrawer(){
  document.getElementById('side-nav').classList.add('-translate-x-full');
  document.getElementById('drawer-overlay').classList.add('hidden');
  document.body.style.overflow='';
}
document.addEventListener('keydown',function(e){if(e.key==='Escape')closeDrawer();});
window.addEventListener('resize',function(){if(window.innerWidth>=1024)closeDrawer();});
</script>
</body></html>
)rawliteral";

const char* PAGE_READINGS PROGMEM = R"rawliteral(
<!DOCTYPE html>

<html class="dark" lang="en"><head>
<meta charset="utf-8"/>
<meta content="width=device-width, initial-scale=1.0" name="viewport"/>
<link href="https://fonts.googleapis.com/css2?family=Inter:wght@400;500;600;700&amp;family=JetBrains+Mono:wght@500;600&amp;display=swap" rel="stylesheet"/>
<link href="https://fonts.googleapis.com/css2?family=Material+Symbols+Outlined:wght,FILL@100..700,0..1&amp;display=block" rel="stylesheet"/>
<script src="https://cdn.tailwindcss.com?plugins=forms,container-queries"></script>
<script id="tailwind-config">
        try {
            tailwind.config = {
                darkMode: "class",
                theme: {
                    extend: {
                        "colors": {
                            "on-secondary-container": "#0c714d",
                            "background": "#0b1c30",
                            "inverse-primary": "#b3c5ff",
                            "surface-tint": "#1155d0",
                            "surface-bright": "#f8f9ff",
                            "on-tertiary-container": "#fff7f1",
                            "surface-container-low": "#112236",
                            "on-primary-fixed": "#001849",
                            "aqi-excellent": "#6cf8bb",
                            "on-primary-fixed-variant": "#003fa4",
                            "secondary": "#6cf8bb",
                            "inverse-on-surface": "#eaf1ff",
                            "on-error": "#ffffff",
                            "on-tertiary-fixed-variant": "#653e00",
                            "secondary-fixed-dim": "#81d8ad",
                            "on-surface": "#ffffff",
                            "primary-fixed": "#dae1ff",
                            "on-error-container": "#93000a",
                            "primary-fixed-dim": "#b3c5ff",
                            "on-secondary-fixed": "#002113",
                            "on-primary-container": "#f8f7ff",
                            "on-surface-variant": "#c2c6d8",
                            "primary": "#b3c5ff",
                            "on-secondary": "#000000",
                            "outline": "#727687",
                            "tertiary-fixed": "#ffddb8",
                            "on-secondary-fixed-variant": "#005236",
                            "surface-variant": "#213145",
                            "error-container": "#ffdad6",
                            "tertiary": "#fcba68",
                            "outline-variant": "#424656",
                            "secondary-container": "#006c49",
                            "surface-container-high": "#1e2f47",
                            "primary-container": "#1155d0",
                            "inverse-surface": "#eaf1ff",
                            "on-primary": "#001849",
                            "on-tertiary-fixed": "#2a1700",
                            "on-background": "#ffffff",
                            "secondary-fixed": "#9df4c8",
                            "on-tertiary": "#000000",
                            "tertiary-fixed-dim": "#fcba68",
                            "tertiary-container": "#9b671c",
                            "surface-dim": "#0b1c30",
                            "error": "#ffb4ab",
                            "surface-container": "#112236",
                            "surface": "#0b1c30",
                            "surface-container-highest": "#213145",
                            "surface-container-lowest": "#071321"
                        },
                        "borderRadius": {
                            "DEFAULT": "1rem",
                            "lg": "2rem",
                            "xl": "3rem",
                            "full": "9999px"
                        },
                        "spacing": {
                            "margin-mobile": "16px",
                            "card-padding": "2rem",
                            "margin-desktop": "40px",
                            "gutter": "24px",
                            "unit": "4px",
                            "container-max-width": "1440px"
                        },
                        "fontFamily": {
                            "label-sm": ["JetBrains Mono"],
                            "headline-lg": ["Inter"],
                            "headline-md": ["Inter"],
                            "display-lg": ["Inter"],
                            "body-lg": ["Inter"],
                            "headline-lg-mobile": ["Inter"],
                            "body-md": ["Inter"],
                            "data-display": ["JetBrains Mono"]
                        },
                        "fontSize": {
                            "label-sm": ["12px", { "lineHeight": "16px", "letterSpacing": "0.05em", "fontWeight": "600" }],
                            "headline-lg": ["32px", { "lineHeight": "40px", "letterSpacing": "-0.01em", "fontWeight": "600" }],
                            "headline-md": ["24px", { "lineHeight": "32px", "fontWeight": "600" }],
                            "display-lg": ["48px", { "lineHeight": "56px", "letterSpacing": "-0.02em", "fontWeight": "700" }],
                            "body-lg": ["18px", { "lineHeight": "28px", "fontWeight": "400" }],
                            "headline-lg-mobile": ["24px", { "lineHeight": "32px", "fontWeight": "600" }],
                            "body-md": ["16px", { "lineHeight": "24px", "fontWeight": "400" }],
                            "data-display": ["20px", { "lineHeight": "24px", "fontWeight": "500" }]
                        }
                    },
                },
            }
        } catch (_e) {}
    </script>
<style>
        .glass-card {
            background: rgba(17, 34, 54, 0.6);
            backdrop-filter: blur(12px);
            border: 1px solid rgba(255, 255, 255, 0.05);
        }
    </style>
</head>
<body class="bg-surface-dim min-h-screen text-on-surface selection:bg-primary-container selection:text-white">
<!-- TopAppBar -->
<header class="bg-surface-container-lowest/80 backdrop-blur-xl border-b border-white/5 flex justify-between items-center px-margin-desktop w-full h-16 z-40 fixed top-0 left-0">
<div class="flex items-center gap-4">
<button aria-label="Open navigation" class="material-symbols-outlined text-on-surface-variant hover:text-primary p-2 rounded-full transition-colors lg:hidden" id="hamburger-btn" onclick="openDrawer()">menu</button>
<span class="font-headline-md text-headline-md font-bold text-primary">EcoPulse IoT</span>
</div>
<div class="flex items-center gap-6">
<div class="hidden md:flex gap-6">
<button class="font-headline-md text-headline-md font-bold text-primary transition-opacity hover:opacity-80">Dashboard</button>
</div>
<div class="flex gap-4">
<button class="material-symbols-outlined text-on-surface-variant hover:text-primary p-2 rounded-full transition-colors">sensors</button>
<button class="material-symbols-outlined text-on-surface-variant hover:text-primary p-2 rounded-full transition-colors">wifi</button>
<button class="material-symbols-outlined text-on-surface-variant hover:text-primary p-2 rounded-full transition-colors">schedule</button>
</div>
</div>
</header>
<!-- Backdrop overlay (mobile) -->
<div class="fixed inset-0 bg-black/60 backdrop-blur-sm z-40 hidden transition-opacity duration-300" id="drawer-overlay" onclick="closeDrawer()"></div>
<!-- SideNavBar -->
<aside class="fixed left-0 top-0 h-full flex flex-col p-6 z-50 bg-surface-container-lowest/95 backdrop-blur-xl border-r border-white/5
  -translate-x-full lg:translate-x-0 transition-transform duration-300 ease-in-out" id="side-nav" style="width:18rem">
<div class="flex items-center justify-between mb-10 pt-4 lg:pt-16">
<div>
<h1 class="font-headline-md text-headline-md font-bold text-primary mb-1">Environmental Monitor</h1>
<p class="font-body-md text-body-md text-on-surface-variant">Solo Project</p>
</div>
<button aria-label="Close navigation" class="material-symbols-outlined text-on-surface-variant hover:text-primary p-1 rounded-full transition-colors lg:hidden" onclick="closeDrawer()">close</button>
</div>
<nav class="flex-1 space-y-2">
<a class="flex items-center gap-4 p-4 text-on-surface-variant hover:bg-white/5 hover:text-white transition-all rounded-xl active:scale-95 duration-200" href="about.html">
<span class="material-symbols-outlined">info</span>
<span class="font-body-md text-body-md">About</span>
</a>
<a class="flex items-center gap-4 p-4 bg-primary/10 text-primary font-bold rounded-xl active:scale-95 duration-200 border border-primary/20" href="#">
<span class="material-symbols-outlined">dashboard</span>
<span class="font-body-md text-body-md">Readings</span>
</a>
<a class="flex items-center gap-4 p-4 text-on-surface-variant hover:bg-white/5 hover:text-white transition-all rounded-xl active:scale-95 duration-200" href="telemetry-dash(graphs).html">
<span class="material-symbols-outlined">analytics</span>
<span class="font-body-md text-body-md">Graphs</span>
</a>
</nav>
<div class="mt-auto space-y-6">
<a href="https://github.com/" target="_blank"><button class="w-full bg-primary text-on-primary py-3 rounded-xl font-bold hover:bg-primary/90 transition-all active:scale-95">Github Repo</button></a>
<div class="flex items-center gap-3">
<div class="w-10 h-10 rounded-full bg-surface-variant overflow-hidden border border-white/10 flex-shrink-0">
<img alt="Roshan Shorey" class="w-full h-full object-cover brightness-110" src="../assets/soloprojprofilepic.jpg"/>
</div>
<div>
<a href="https://www.linkedin.com/in/roshan-shorey-418248371/" target="_blank"><p class="font-body-md text-body-md font-bold text-on-surface">Roshan Shorey</p></a>
<div class="font-label-sm text-label-sm text-on-surface-variant">2nd Year, SVNIT Surat</div>
</div>
</div>
</div>
</aside>
<!-- Main Content -->
<main class="pt-24 pb-12 px-margin-mobile lg:pl-72 lg:pr-margin-desktop min-h-screen">
<!-- Header Text -->
<div class="mb-8">
<h2 class="font-headline-lg text-headline-lg text-on-surface">Sensor Readings</h2>
<p class="font-body-lg text-body-lg text-on-surface-variant mt-2">Current environmental telemetry from Alpine Valley sensor array.</p>
</div>
<!-- Bento Grid -->
<div class="grid grid-cols-1 md:grid-cols-2 lg:grid-cols-3 gap-6">
<!-- 1. Temperature -->
<div class="glass-card rounded-[32px] p-8 flex flex-col justify-between min-h-[220px]">
<div>
<div class="flex justify-between items-start">
<span class="font-label-sm text-label-sm text-on-surface-variant uppercase tracking-widest block mb-4">Ambient Temperature</span>
<span class="material-symbols-outlined text-secondary opacity-50">thermostat</span>
</div>
<div class="flex items-baseline gap-2">
<!-- VARIABLE_HOLDER: temperature -->
<span id="val-temp" class="font-display-lg text-6xl text-white">24.8</span>
<span class="font-headline-md text-headline-md text-secondary">°C</span>
</div>
</div>
<div class="mt-4 pt-4 border-t border-white/5">
<span class="font-label-sm text-label-sm text-secondary uppercase font-bold tracking-tighter">Normal Range</span>
</div>
</div>
<!-- 2. Relative Humidity -->
<div class="glass-card rounded-[32px] p-8 flex flex-col justify-between min-h-[220px]">
<div>
<div class="flex justify-between items-start">
<span class="font-label-sm text-label-sm text-on-surface-variant uppercase tracking-widest block mb-4">Relative Humidity</span>
<span class="material-symbols-outlined text-primary opacity-50">water_drop</span>
</div>
<div class="flex items-baseline gap-2">
<!-- VARIABLE_HOLDER: humidity -->
<span id="val-hum" class="font-display-lg text-6xl text-white">64</span>
<span class="font-data-display text-data-display text-primary/60">%</span>
</div>
</div>
<div class="mt-4 pt-4 border-t border-white/5">
<span class="font-label-sm text-label-sm text-on-surface-variant uppercase font-bold tracking-tighter">Stable Environment</span>
</div>
</div>
<!-- 3. Air Quality Index -->
<div class="glass-card rounded-[32px] p-8 flex flex-col justify-between min-h-[220px]">
<div>
<div class="flex justify-between items-start">
<span class="font-label-sm text-label-sm text-on-surface-variant uppercase tracking-widest block mb-4">Air Quality Index</span>
<span class="material-symbols-outlined text-secondary opacity-50">air</span>
</div>
<div class="flex items-baseline gap-2">
<!-- VARIABLE_HOLDER: aqi -->
<span id="val-aqi" class="font-display-lg text-6xl text-white">42</span>
<span id="val-aqi-label" class="font-label-sm text-label-sm px-2 py-0.5 bg-secondary text-on-secondary rounded font-bold uppercase ml-2">Excellent</span>
</div>
</div>
<div class="mt-4 pt-4 border-t border-white/5">
<span class="font-label-sm text-label-sm text-on-surface-variant uppercase font-bold tracking-tighter">Healthy Conditions</span>
</div>
</div>
<!-- 4. Barometric Pressure -->
<div class="glass-card rounded-[32px] p-8 flex flex-col justify-between min-h-[220px]">
<div>
<div class="flex justify-between items-start">
<span class="font-label-sm text-label-sm text-on-surface-variant uppercase tracking-widest block mb-4">Baro Pressure</span>
<span class="material-symbols-outlined text-tertiary-fixed-dim opacity-50">compress</span>
</div>
<div class="flex items-baseline gap-2">
<!-- VARIABLE_HOLDER: pressure -->
<span id="val-pres" class="font-display-lg text-5xl text-white">1013.2</span>
<span class="font-label-sm text-on-surface-variant ml-1 font-bold">hPa</span>
</div>
</div>
<div class="mt-4 pt-4 border-t border-white/5">
<span class="font-label-sm text-label-sm text-tertiary-fixed-dim uppercase font-bold tracking-tighter">Stable Pressure</span>
</div>
</div>
<!-- 5. Altitude -->
<div class="glass-card rounded-[32px] p-8 flex flex-col justify-between min-h-[220px]">
<div>
<div class="flex justify-between items-start">
<span class="font-label-sm text-label-sm text-on-surface-variant uppercase tracking-widest block mb-4">Altitude</span>
<span class="material-symbols-outlined text-tertiary opacity-50">landscape</span>
</div>
<div class="flex items-baseline gap-2">
<!-- VARIABLE_HOLDER: altitude -->
<span id="val-alt" class="font-display-lg text-5xl text-white">1,245</span>
<span class="font-body-md text-on-surface-variant ml-1 font-bold">m</span>
</div>
</div>
<div class="mt-4 pt-4 border-t border-white/5">
<span class="font-label-sm text-label-sm text-on-surface-variant uppercase font-bold tracking-tighter">ASL Reading</span>
</div>
</div>
<!-- 6. Rain Sensor -->
<div class="glass-card rounded-[32px] p-8 flex flex-col justify-between min-h-[220px]">
<div>
<div class="flex justify-between items-start">
<span class="font-label-sm text-label-sm text-on-surface-variant uppercase tracking-widest block mb-4">Rain Sensor</span>
<span class="material-symbols-outlined text-secondary opacity-50">rainy</span>
</div>
<div class="flex items-baseline gap-2">
<!-- VARIABLE_HOLDER: is_raining -->
<span id="val-rain" class="font-display-lg text-6xl text-white">No</span>
<span id="val-rain-label" class="font-body-md text-on-surface-variant ml-2 font-bold opacity-60">Rain</span>
</div>
</div>
<div class="mt-4 pt-4 border-t border-white/5">
<span class="font-label-sm text-label-sm text-on-surface-variant uppercase font-bold tracking-tighter">Dry Surface</span>
</div>
</div>
</div>
<!-- System Alerts -->
<section class="mt-12">
<h3 class="font-headline-md text-headline-md text-on-surface mb-6">Recent Node Activity</h3>
<div class="space-y-4">
<div class="glass-card p-4 rounded-2xl flex items-center justify-between border-l-4 border-secondary/60">
<div class="flex items-center gap-4">
<div class="w-10 h-10 rounded-full bg-secondary/10 flex items-center justify-center">
<span class="material-symbols-outlined text-secondary">check_circle</span>
</div>
<div>
<p class="font-body-md font-bold text-white">Calibration Successful</p>
<p class="font-label-sm text-on-surface-variant">Node #042 successfully recalibrated humidity sensor.</p>
</div>
</div>
<span class="font-label-sm text-on-surface-variant">2 mins ago</span>
</div>
<div class="glass-card p-4 rounded-2xl flex items-center justify-between border-l-4 border-primary/60">
<div class="flex items-center gap-4">
<div class="w-10 h-10 rounded-full bg-primary/10 flex items-center justify-center">
<span class="material-symbols-outlined text-primary">cloud_sync</span>
</div>
<div>
<p class="font-body-md font-bold text-white">Data Burst Transmitted</p>
<p class="font-label-sm text-on-surface-variant">Full environment telemetry sent to Central Cloud Server.</p>
</div>
</div>
<span class="font-label-sm text-on-surface-variant">14 mins ago</span>
</div>
</div>
</section>
</main>
<script>
function openDrawer(){
  document.getElementById('side-nav').classList.remove('-translate-x-full');
  document.getElementById('drawer-overlay').classList.remove('hidden');
  document.body.style.overflow='hidden';
}
function closeDrawer(){
  document.getElementById('side-nav').classList.add('-translate-x-full');
  document.getElementById('drawer-overlay').classList.add('hidden');
  document.body.style.overflow='';
}
document.addEventListener('keydown',function(e){if(e.key==='Escape')closeDrawer();});
window.addEventListener('resize',function(){if(window.innerWidth>=1024)closeDrawer();});

// REAL-TIME DATA FETCHING
function updateDashboard() {
  fetch('/api/data')
    .then(response => response.json())
    .then(data => {
      // data = [Temperature, Humidity, Pressure, Altitude, AQI, Rain_ADC]
      if(data.length >= 6) {
        document.getElementById('val-temp').innerText = data[0].toFixed(2);
        document.getElementById('val-hum').innerText = data[1].toFixed(2);
        document.getElementById('val-pres').innerText = data[2].toFixed(2);
        document.getElementById('val-alt').innerText = data[3].toFixed(2);
        
        // AQI Logic
        let aqi = Math.round(data[4]);
        document.getElementById('val-aqi').innerText = aqi;
        let aqiLabel = document.getElementById('val-aqi-label');
        if (aqi <= 50) { aqiLabel.innerText = "Excellent"; aqiLabel.className = "font-label-sm text-label-sm px-2 py-0.5 bg-secondary text-on-secondary rounded font-bold uppercase ml-2"; }
        else if (aqi <= 100) { aqiLabel.innerText = "Moderate"; aqiLabel.className = "font-label-sm text-label-sm px-2 py-0.5 bg-yellow-500 text-black rounded font-bold uppercase ml-2"; }
        else if (aqi <= 200) { aqiLabel.innerText = "Poor"; aqiLabel.className = "font-label-sm text-label-sm px-2 py-0.5 bg-orange-500 text-white rounded font-bold uppercase ml-2"; }
        else { aqiLabel.innerText = "Danger"; aqiLabel.className = "font-label-sm text-label-sm px-2 py-0.5 bg-red-600 text-white rounded font-bold uppercase ml-2"; }

        // Rain Logic
        let rainAdc = data[5];
        let rainVal = document.getElementById('val-rain');
        let rainLabel = document.getElementById('val-rain-label');
        if (rainAdc >= 4000) { rainVal.innerText = "Clear"; rainLabel.innerText = "Skies"; }
        else if (rainAdc >= 3200) { rainVal.innerText = "Mist"; rainLabel.innerText = "Drizzling"; }
        else if (rainAdc >= 2200) { rainVal.innerText = "Light"; rainLabel.innerText = "Rain"; }
        else if (rainAdc >= 1000) { rainVal.innerText = "Heavy"; rainLabel.innerText = "Shower"; }
        else { rainVal.innerText = "Flood"; rainLabel.innerText = "Risk"; }
      }
    })
    .catch(error => console.error('Error fetching sensor data:', error));
}

// Fetch immediately, then every 3 seconds
updateDashboard();
setInterval(updateDashboard, 3000);
</script>
</body></html>
)rawliteral";

const char* PAGE_GRAPHS PROGMEM = R"rawliteral(
<!DOCTYPE html>

<html class="dark" lang="en"><head>
<meta charset="utf-8"/>
<meta content="width=device-width, initial-scale=1.0" name="viewport"/>
<link href="https://fonts.googleapis.com/css2?family=Inter:wght@400;500;600;700&amp;family=JetBrains+Mono:wght@500;600&amp;display=swap" rel="stylesheet"/>
<link href="https://fonts.googleapis.com/css2?family=Material+Symbols+Outlined:wght,FILL@100..700,0..1&amp;display=block" rel="stylesheet"/>
<script src="https://cdn.tailwindcss.com?plugins=forms,container-queries"></script>
<script id="tailwind-config">
        try {
            tailwind.config = {
                darkMode: "class",
                theme: {
                    extend: {
                        "colors": {
                            "on-secondary-container": "#0c714d",
                            "background": "#0b1c30",
                            "inverse-primary": "#b3c5ff",
                            "surface-tint": "#1155d0",
                            "surface-bright": "#f8f9ff",
                            "on-tertiary-container": "#fff7f1",
                            "surface-container-low": "#112236",
                            "on-primary-fixed": "#001849",
                            "aqi-excellent": "#6cf8bb",
                            "on-primary-fixed-variant": "#003fa4",
                            "secondary": "#6cf8bb",
                            "inverse-on-surface": "#eaf1ff",
                            "on-error": "#ffffff",
                            "on-tertiary-fixed-variant": "#653e00",
                            "secondary-fixed-dim": "#81d8ad",
                            "on-surface": "#ffffff",
                            "primary-fixed": "#dae1ff",
                            "on-error-container": "#93000a",
                            "primary-fixed-dim": "#b3c5ff",
                            "on-secondary-fixed": "#002113",
                            "on-primary-container": "#f8f7ff",
                            "on-surface-variant": "#c2c6d8",
                            "primary": "#b3c5ff",
                            "on-secondary": "#000000",
                            "outline": "#727687",
                            "tertiary-fixed": "#ffddb8",
                            "on-secondary-fixed-variant": "#005236",
                            "surface-variant": "#213145",
                            "error-container": "#ffdad6",
                            "tertiary": "#fcba68",
                            "outline-variant": "#424656",
                            "secondary-container": "#006c49",
                            "surface-container-high": "#1e2f47",
                            "primary-container": "#1155d0",
                            "inverse-surface": "#eaf1ff",
                            "on-primary": "#001849",
                            "on-tertiary-fixed": "#2a1700",
                            "on-background": "#ffffff",
                            "secondary-fixed": "#9df4c8",
                            "on-tertiary": "#000000",
                            "tertiary-fixed-dim": "#fcba68",
                            "tertiary-container": "#9b671c",
                            "surface-dim": "#0b1c30",
                            "error": "#ffb4ab",
                            "surface-container": "#112236",
                            "surface": "#0b1c30",
                            "surface-container-highest": "#213145",
                            "surface-container-lowest": "#071321"
                        },
                        "borderRadius": {
                            "DEFAULT": "1rem",
                            "lg": "2rem",
                            "xl": "3rem",
                            "full": "9999px"
                        },
                        "spacing": {
                            "margin-mobile": "16px",
                            "card-padding": "2rem",
                            "margin-desktop": "40px",
                            "gutter": "24px",
                            "unit": "4px",
                            "container-max-width": "1440px"
                        },
                        "fontFamily": {
                            "label-sm": ["JetBrains Mono"],
                            "headline-lg": ["Inter"],
                            "headline-md": ["Inter"],
                            "display-lg": ["Inter"],
                            "body-lg": ["Inter"],
                            "headline-lg-mobile": ["Inter"],
                            "body-md": ["Inter"],
                            "data-display": ["JetBrains Mono"]
                        },
                        "fontSize": {
                            "label-sm": ["12px", { "lineHeight": "16px", "letterSpacing": "0.05em", "fontWeight": "600" }],
                            "headline-lg": ["32px", { "lineHeight": "40px", "letterSpacing": "-0.01em", "fontWeight": "600" }],
                            "headline-md": ["24px", { "lineHeight": "32px", "fontWeight": "600" }],
                            "display-lg": ["48px", { "lineHeight": "56px", "letterSpacing": "-0.02em", "fontWeight": "700" }],
                            "body-lg": ["18px", { "lineHeight": "28px", "fontWeight": "400" }],
                            "headline-lg-mobile": ["24px", { "lineHeight": "32px", "fontWeight": "600" }],
                            "body-md": ["16px", { "lineHeight": "24px", "fontWeight": "400" }],
                            "data-display": ["20px", { "lineHeight": "24px", "fontWeight": "500" }]
                        }
                    },
                },
            }
        } catch (_e) {}
    </script>
<style>
        .glass-card {
            background: rgba(17, 34, 54, 0.6);
            backdrop-filter: blur(12px);
            border: 1px solid rgba(255, 255, 255, 0.05);
        }
    </style>
</head>
<body class="bg-surface-dim min-h-screen text-on-surface selection:bg-primary-container selection:text-white">
<!-- TopAppBar -->
<header class="bg-surface-container-lowest/80 backdrop-blur-xl border-b border-white/5 flex justify-between items-center px-margin-desktop w-full h-16 z-40 fixed top-0 left-0">
<div class="flex items-center gap-4">
<button aria-label="Open navigation" class="material-symbols-outlined text-on-surface-variant hover:text-primary p-2 rounded-full transition-colors lg:hidden" id="hamburger-btn" onclick="openDrawer()">menu</button>
<span class="font-headline-md text-headline-md font-bold text-primary">EcoPulse IoT</span>
</div>
<div class="flex items-center gap-6">
<div class="hidden md:flex gap-6">
<button class="font-body-md text-primary font-semibold">Graphs View</button>
</div>
<div class="flex gap-4">
<button class="material-symbols-outlined text-on-surface-variant hover:text-primary p-2 rounded-full transition-colors">sensors</button>
<button class="material-symbols-outlined text-on-surface-variant hover:text-primary p-2 rounded-full transition-colors">wifi</button>
<button class="material-symbols-outlined text-on-surface-variant hover:text-primary p-2 rounded-full transition-colors">settings</button>
</div>
</div>
</header>
<!-- Backdrop overlay (mobile) -->
<div class="fixed inset-0 bg-black/60 backdrop-blur-sm z-40 hidden transition-opacity duration-300" id="drawer-overlay" onclick="closeDrawer()"></div>
<!-- SideNavBar -->
<aside class="fixed left-0 top-0 h-full flex flex-col p-6 z-50 bg-surface-container-lowest/95 backdrop-blur-xl border-r border-white/5 w-72
  -translate-x-full lg:translate-x-0 transition-transform duration-300 ease-in-out flex flex-col" id="side-nav" style="width:18rem">
<div class="flex items-center justify-between mb-10 pt-4 lg:pt-16">
<div>
<h1 class="font-headline-md text-headline-md font-bold text-primary mb-1">Environmental Monitor</h1>
<p class="font-body-md text-body-md text-on-surface-variant">Solo Project</p>
</div>
<button aria-label="Close navigation" class="material-symbols-outlined text-on-surface-variant hover:text-primary p-1 rounded-full transition-colors lg:hidden" onclick="closeDrawer()">close</button>
</div>
<nav class="flex-1 space-y-2">
<a class="flex items-center gap-4 p-4 text-on-surface-variant hover:bg-white/5 hover:text-white transition-all rounded-xl active:scale-95 duration-200" href="about.html">
<span class="material-symbols-outlined">info</span>
<span class="font-body-md text-body-md">About</span>
</a>
<a class="flex items-center gap-4 p-4 text-on-surface-variant hover:bg-white/5 hover:text-white transition-all rounded-xl active:scale-95 duration-200" href="telemetry-dash-readings.html">
<span class="material-symbols-outlined">dashboard</span>
<span class="font-body-md text-body-md">Readings</span>
</a>
<a class="flex items-center gap-4 p-4 bg-primary/10 text-primary font-bold rounded-xl active:scale-95 duration-200 border border-primary/20" href="#">
<span class="material-symbols-outlined">analytics</span>
<span class="font-body-md text-body-md">Graphs</span>
</a>
</nav>
<div class="mt-auto space-y-6">
<a href="https://github.com/" target="_blank"><button class="w-full bg-primary text-on-primary py-3 rounded-xl font-bold hover:opacity-90 transition-all active:scale-95">Github Repo</button></a>
<div class="flex items-center gap-3">
<div class="w-10 h-10 rounded-full bg-surface-variant overflow-hidden border border-white/10 flex-shrink-0">
<img alt="Roshan Shorey" class="w-full h-full object-cover brightness-110" src="../assets/soloprojprofilepic.jpg"/>
</div>
<div>
<a href="https://www.linkedin.com/in/roshan-shorey-418248371/" target="_blank"><p class="font-body-md text-body-md font-bold text-on-surface">Roshan Shorey</p></a>
<p class="font-label-sm text-label-sm text-on-surface-variant">2nd Year, SVNIT Surat</p>
</div>
</div>
</div>
</aside>
<!-- Main Content -->
<main class="pt-24 pb-12 px-margin-mobile lg:pl-72 lg:pr-margin-desktop min-h-screen">
<!-- Header Text -->
<div class="mb-8">
<h2 class="font-headline-lg text-headline-lg text-on-surface">Telemetry Analysis</h2>
<p class="font-body-lg text-body-lg text-on-surface-variant mt-2">Historic trends from the sensor node network.</p>
</div>
<!-- Graphs Grid -->
<div class="grid grid-cols-1 md:grid-cols-2 lg:grid-cols-3 gap-6">
<!-- 1. Temperature Graph -->
<div class="glass-card rounded-2xl p-6 flex flex-col h-80">
<div class="flex justify-between items-start mb-6">
<div>
<span class="font-label-sm text-label-sm text-on-surface-variant uppercase tracking-wider block mb-1">Temperature</span>
<span class="font-headline-md text-white"><span id="graph-temp">24.8</span> <span class="text-secondary text-sm">°C</span></span>
</div>
<span class="material-symbols-outlined text-secondary opacity-50">thermostat</span>
</div>
<div class="flex-1 w-full relative">
<!-- VARIABLE_HOLDER: TEMPERATURE_DATA -->
<svg class="w-full h-full overflow-visible" preserveaspectratio="none" viewbox="0 0 100 60">
<path id="svg-temp-line" d="M0 50 Q 20 20 40 45 T 100 30" fill="none" stroke="#6cf8bb" stroke-width="2" vector-effect="non-scaling-stroke"></path>
<path id="svg-temp-fill" d="M0 50 Q 20 20 40 45 T 100 30 V 60 H 0 Z" fill="rgba(108, 248, 187, 0.05)"></path>
</svg>
</div>
<div class="mt-4 flex justify-between font-label-sm text-on-surface-variant">
<span>08:00</span>
<span>12:00</span>
<span>16:00</span>
</div>
</div>
<!-- 2. Humidity Graph -->
<div class="glass-card rounded-2xl p-6 flex flex-col h-80">
<div class="flex justify-between items-start mb-6">
<div>
<span class="font-label-sm text-label-sm text-on-surface-variant uppercase tracking-wider block mb-1">Humidity</span>
<span class="font-headline-md text-white"><span id="graph-hum">64</span> <span class="text-primary text-sm">%</span></span>
</div>
<span class="material-symbols-outlined text-primary opacity-50">water_drop</span>
</div>
<div class="flex-1 w-full relative">
<!-- VARIABLE_HOLDER: HUMIDITY_DATA -->
<svg class="w-full h-full overflow-visible" preserveaspectratio="none" viewbox="0 0 100 60">
<path id="svg-hum-line" d="M0 40 Q 25 30 50 50 T 100 20" fill="none" stroke="#b3c5ff" stroke-width="2" vector-effect="non-scaling-stroke"></path>
<path id="svg-hum-fill" d="M0 40 Q 25 30 50 50 T 100 20 V 60 H 0 Z" fill="rgba(179, 197, 255, 0.05)"></path>
</svg>
</div>
<div class="mt-4 flex justify-between font-label-sm text-on-surface-variant">
<span>08:00</span>
<span>12:00</span>
<span>16:00</span>
</div>
</div>
<!-- 3. Air Quality Index (AQI) Graph -->
<div class="glass-card rounded-2xl p-6 flex flex-col h-80">
<div class="flex justify-between items-start mb-6">
<div>
<span class="font-label-sm text-label-sm text-on-surface-variant uppercase tracking-wider block mb-1">Air Quality (AQI)</span>
<span class="font-headline-md text-white"><span id="graph-aqi">42</span> <span id="graph-aqi-label" class="text-aqi-excellent text-sm">Excellent</span></span>
</div>
<span class="material-symbols-outlined text-aqi-excellent opacity-50">air</span>
</div>
<div class="flex-1 w-full relative">
<!-- VARIABLE_HOLDER: AQI_DATA -->
<svg class="w-full h-full overflow-visible" preserveaspectratio="none" viewbox="0 0 100 60">
<path id="svg-aqi-line" d="M0 55 L 20 40 L 40 45 L 60 30 L 80 35 L 100 25" fill="none" stroke="#6cf8bb" stroke-linecap="round" stroke-width="2" vector-effect="non-scaling-stroke"></path>
<path id="svg-aqi-fill" d="M0 55 L 20 40 L 40 45 L 60 30 L 80 35 L 100 25 V 60 H 0 Z" fill="rgba(108, 248, 187, 0.05)"></path>
</svg>
</div>
<div class="mt-4 flex justify-between font-label-sm text-on-surface-variant">
<span>08:00</span>
<span>12:00</span>
<span>16:00</span>
</div>
</div>
<!-- 4. Barometric Pressure Graph -->
<div class="glass-card rounded-2xl p-6 flex flex-col h-80">
<div class="flex justify-between items-start mb-6">
<div>
<span class="font-label-sm text-label-sm text-on-surface-variant uppercase tracking-wider block mb-1">Pressure</span>
<span class="font-headline-md text-white"><span id="graph-pres">1013.2</span> <span class="text-tertiary-fixed-dim text-sm">hPa</span></span>
</div>
<span class="material-symbols-outlined text-tertiary opacity-50">speed</span>
</div>
<div class="flex-1 w-full relative">
<!-- VARIABLE_HOLDER: PRESSURE_DATA -->
<svg class="w-full h-full overflow-visible" preserveaspectratio="none" viewbox="0 0 100 60">
<path id="svg-pres-line" d="M0 30 Q 33 28 66 32 T 100 30" fill="none" stroke="#fcba68" stroke-width="2" vector-effect="non-scaling-stroke"></path>
<path id="svg-pres-fill" d="M0 30 Q 33 28 66 32 T 100 30 V 60 H 0 Z" fill="rgba(252, 186, 104, 0.05)"></path>
</svg>
</div>
<div class="mt-4 flex justify-between font-label-sm text-on-surface-variant">
<span>08:00</span>
<span>12:00</span>
<span>16:00</span>
</div>
</div>
<!-- 5. Altitude Graph -->
<div class="lg:col-span-2 glass-card rounded-2xl p-6 flex flex-col h-80">
<div class="flex justify-between items-start mb-6">
<div>
<span class="font-label-sm text-label-sm text-on-surface-variant uppercase tracking-wider block mb-1">Altitude ASL</span>
<span class="font-headline-md text-white"><span id="graph-alt">1,245</span> <span class="text-tertiary text-sm">m</span></span>
</div>
<span class="material-symbols-outlined text-tertiary opacity-50">landscape</span>
</div>
<div class="flex-1 w-full relative px-4">
<!-- VARIABLE_HOLDER: ALTITUDE_DATA -->
<svg class="w-full h-full overflow-visible" preserveaspectratio="none" viewbox="0 0 200 60">
<path id="svg-alt-line" d="M0 50 L 20 48 L 40 51 L 60 45 L 80 46 L 100 42 L 120 44 L 140 38 L 160 40 L 180 35 L 200 37" fill="none" stroke="#fcba68" stroke-linecap="round" stroke-width="2" vector-effect="non-scaling-stroke"></path>
<path id="svg-alt-fill" d="M0 50 L 20 48 L 40 51 L 60 45 L 80 46 L 100 42 L 120 44 L 140 38 L 160 40 L 180 35 L 200 37 V 60 H 0 Z" fill="rgba(252, 186, 104, 0.05)"></path>
</svg>
</div>
<div class="mt-4 flex justify-between font-label-sm text-on-surface-variant">
<span>Week 1</span>
<span>Week 2</span>
<span>Week 3</span>
<span>Week 4</span>
</div>
</div>
</div>
<!-- Alert / System Status -->
<section class="mt-12">
<h3 class="font-headline-md text-headline-md text-on-surface mb-6">System Health</h3>
<div class="grid grid-cols-1 md:grid-cols-2 gap-4">
<div class="glass-card p-4 rounded-xl flex items-center gap-4">
<div class="w-10 h-10 rounded-full bg-secondary/10 flex items-center justify-center">
<span class="material-symbols-outlined text-secondary">database</span>
</div>
<div>
<p class="font-body-md font-bold text-white">Database Sync</p>
<p class="font-label-sm text-on-surface-variant">Last entry: 1 minute ago</p>
</div>
</div>
<div class="glass-card p-4 rounded-xl flex items-center gap-4">
<div class="w-10 h-10 rounded-full bg-primary/10 flex items-center justify-center">
<span class="material-symbols-outlined text-primary">analytics</span>
</div>
<div>
<p class="font-body-md font-bold text-white">Processing Node</p>
<p class="font-label-sm text-on-surface-variant">Averaging 12 samples/min</p>
</div>
</div>
</div>
</section>
</main>
<script>
function openDrawer(){
  document.getElementById('side-nav').classList.remove('-translate-x-full');
  document.getElementById('drawer-overlay').classList.remove('hidden');
  document.body.style.overflow='hidden';
}
function closeDrawer(){
  document.getElementById('side-nav').classList.add('-translate-x-full');
  document.getElementById('drawer-overlay').classList.add('hidden');
  document.body.style.overflow='';
}
// Close on Escape key
document.addEventListener('keydown',function(e){if(e.key==='Escape')closeDrawer();});
// Auto-close on resize to desktop
window.addEventListener('resize',function(){if(window.innerWidth>=1024)closeDrawer();});

// REAL-TIME GRAPHS
const MAX_POINTS = 20;
let historyData = { temp: [], hum: [], aqi: [], pres: [], alt: [] };

function updateSVG(type, value, min, max, svgWidth, autoScale = false) {
  historyData[type].push(value);
  if (historyData[type].length > MAX_POINTS) historyData[type].shift();

  let currentMin = min;
  let currentMax = max;

  if (autoScale && historyData[type].length > 1) {
    let vals = historyData[type];
    let minVal = Math.min(...vals);
    let maxVal = Math.max(...vals);
    let padding = (maxVal - minVal) * 0.5; // generous padding
    if (padding === 0) padding = 1;
    currentMin = minVal - padding;
    currentMax = maxVal + padding;
  }

  let linePath = "";
  let fillPath = "";
  
  // Calculate X step
  let step = historyData[type].length > 1 ? svgWidth / (historyData[type].length - 1) : svgWidth;
  
  for (let i = 0; i < historyData[type].length; i++) {
    let val = historyData[type][i];
    // Map value to Y coordinate (0 at top, 60 at bottom)
    let y = 60 - ((val - currentMin) / (currentMax - currentMin) * 60);
    if (y < 5) y = 5;
    if (y > 55) y = 55;
    
    let x = i * step;
    if (i === 0) {
      linePath += `M ${x} ${y} `;
      fillPath += `M ${x} ${y} `;
    } else {
      linePath += `L ${x} ${y} `;
      fillPath += `L ${x} ${y} `;
    }
  }
  
  if (historyData[type].length > 0) {
    fillPath += `V 60 H 0 Z`;
    document.getElementById(`svg-${type}-line`).setAttribute("d", linePath);
    document.getElementById(`svg-${type}-fill`).setAttribute("d", fillPath);
  }
}

function updateGraphs() {
  fetch('/api/data')
    .then(response => response.json())
    .then(data => {
      // data = [Temperature, Humidity, Pressure, Altitude, AQI, Rain_ADC]
      if(data.length >= 6) {
        document.getElementById('graph-temp').innerText = data[0].toFixed(2);
        document.getElementById('graph-hum').innerText = data[1].toFixed(2);
        document.getElementById('graph-pres').innerText = data[2].toFixed(2);
        document.getElementById('graph-alt').innerText = data[3].toFixed(2);
        
        // AQI Logic
        let aqi = Math.round(data[4]);
        document.getElementById('graph-aqi').innerText = aqi;
        let aqiLabel = document.getElementById('graph-aqi-label');
        if (aqi <= 50) { aqiLabel.innerText = "Excellent"; aqiLabel.className = "text-secondary text-sm font-bold uppercase"; }
        else if (aqi <= 100) { aqiLabel.innerText = "Moderate"; aqiLabel.className = "text-yellow-500 text-sm font-bold uppercase"; }
        else if (aqi <= 200) { aqiLabel.innerText = "Poor"; aqiLabel.className = "text-orange-500 text-sm font-bold uppercase"; }
        else { aqiLabel.innerText = "Danger"; aqiLabel.className = "text-red-600 text-sm font-bold uppercase"; }

        // Update SVGs (type, value, min, max, svgWidth, autoScale)
        updateSVG('temp', data[0], 10, 45, 100, true);
        updateSVG('hum', data[1], 20, 90, 100, true);
        updateSVG('aqi', data[4], 0, 300, 100, false);
        updateSVG('pres', data[2], 980, 1050, 100, true);
        updateSVG('alt', data[3], 0, 2000, 200, true);
      }
    })
    .catch(error => console.error('Error fetching graph data:', error));
}

// Start polling
setInterval(updateGraphs, 3000);
</script>
</body></html>
)rawliteral";

#endif

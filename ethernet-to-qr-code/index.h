const char index_html[] PROGMEM = R"rawliteral(
<!DOCTYPE HTML>
<html lang='en'>
    <head>
        <meta charset='utf-8'>
        <script src= 'https://cdnjs.cloudflare.com/ajax/libs/qrcodejs/1.0.0/qrcode.min.js'></script>
        <style>
            .header {
                text-align: center;
            }

            #qrcode {
                display: flex; 
                justify-content: center;
                align-items: center;
            }

        </style>
    </head>

    <body>
        <div class="header">
            <h1 style>QR Code Image Transfer</h1>
            <p>Please scan the QR code below.</p>
        </div>
        
        <div id='qrcode'></div>
        )rawliteral";

const char index_html2[] PROGMEM = R"rawliteral(
    </body>
</html>)rawliteral";
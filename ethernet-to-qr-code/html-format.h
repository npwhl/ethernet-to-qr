const char index_html[] PROGMEM = R"rawliteral(
<!DOCTYPE HTML>
<html lang='en'>
    <head>
        <meta charset='utf-8'>
        <script src= 'https://cdnjs.cloudflare.com/ajax/libs/qrcodejs/1.0.0/qrcode.min.js'></script>
    </head>

    <body>
        <h1>QR Code Image Transfer</h1>
        <p>Please scan the QR code below.</p>
        
        <div id='qrcode'></div>
        <script var qrcode = new QRCode('qrcode', 'http://" + toSt + ":8080/></script>
    </body>
</html>)rawliteral";
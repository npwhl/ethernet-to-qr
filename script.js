// Script.js 
// create a new QRCode instance 
let qrcode = new QRCode( 
    document.querySelector(".qrcode") 
); 
  
// Initial QR code generation 
// with a default message 
qrcode.makeCode("Why did you scan me?"); 
  
// Function to generate QR 
// code based on user input 
function generateQr(data) { 
    qrcode.makeCode(data); 
}

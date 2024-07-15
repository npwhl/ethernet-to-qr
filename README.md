# ethernet-to-qr
An experiment project intended to generate a qr code to transfer images on
a unique, local web page. This project attempts to replicate the Nintendo
Switch's current method of image transfering, which involves:

    1. Make a QR code to connect the transfer device (ex. a smart phone) to
       a unique IP address. 
    2. Make a second QR code to transfer selected images through the unique
       IP address.

I would like this project to work without the image host device having to 
connect to the internet, since the process on the Nintendo Switch only requires 
internet connectivity on the smartphone. So, the image host device needs to host
its own IP address and send it to the transfer device to connect to. 

In the future, I would like this project to work without an Arduino. For example, 
I would like to have this project work on the Nintendo DS to give it a way to 
transfer images to another device without using an SD card or Facebook. 

Hardware: Adafruit Ethernet FeatherWing, Adafruit Rp2040 Feather w/ RFM95 LoRa
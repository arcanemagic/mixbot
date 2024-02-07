The system is controlled though an Arduino Nano 33 IoT, and communicates over HTTP. There is a web app that can be used to provide input on which drink to mix, or specify a custom amount for each ingredient. The amount of liquid dispensed is accurately measured and controlled through peristaltic pumps, which are controlled with L298N motor drivers. The drink produced is completely safe to consume, since all liquid is only ever touched by food-grade silicon tubing. This is a very cost-effective project (<$70), and is easily expandable, since each pump/bottle component is modular. This allows for easy replacement of bottles, or the addition of more ingredients.

To run, upload mixbot.ino to your Arduino Nano 33 IoT and connect to the `cocktail` WiFi network from your phone. This will allow you to upload your drink order.

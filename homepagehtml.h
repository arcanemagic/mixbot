 #include <string>
 

std::string indexhtml = R"(<!DOCTYPE html>
    <html>
    <head>
      <style>
        body {
          background-color: powderblue;
        }
          
        h1 {
            color: red;
          }
        
        p {
          color: black;
        }
        </style>
    </head>
    <body>

    <h1>Order Drinks Here</h1>
    <h3>Welcome! Choose a drink or specify your own:</h3>

    Click <a href=\"/H\">here</a> turn the LED on<br>
    Click <a href=\"/L\">here</a> turn the LED off<br>
    Click <a href=\"/1-1-1-1\">here</a> for drink 1<br>
    Click <a href=\"/1-2-3-4\">here</a> for drink 2<br>
    Click <a href=\"/3-3-4-4\">here</a> for drink 3<br>
    Click <a href=\"/2-2-3-4\">here</a> for drink 4<br>

    </body>
    </html>)"; 

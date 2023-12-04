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

     <form method="get" action="" enctype="text/plain">
        <p>Drink 1:</p>
        <input type="radio" id="measurement1" name="drink1" value="measurement1">
        <label for="measurement1">Measurement 1</label><br>
        <input type="radio" id="measurement2" name="drink1" value="measurement2">
        <label for="measurement2">Measurement 2</label><br>
        <input type="radio" id="measurement3" name="drink1" value="measurement3">
        <label for="measurement3">Measurement 3</label><br>
        <input type="radio" id="measurement4" name="drink1" value="measurement4">
        <label for="measurement4">Measurement 4</label><br>

        <br>

        <p>Drink 2</p>
        <input type="radio" id="measurement1" name="drink2" value="measurement1">
        <label for="measurement1">Measurement 1</label><br>
        <input type="radio" id="measurement2" name="drink2" value="measurement2">
        <label for="measurement2">Measurement 2</label><br>
        <input type="radio" id="measurement3" name="drink2" value="measurement3">
        <label for="measurement3">Measurement 3</label><br>
        <input type="radio" id="measurement4" name="drink2" value="measurement4">
        <label for="measurement4">Measurement 4</label><br>

        <br>

        <p>Drink 3:</p>
        <input type="radio" id="measurement1" name="drink3" value="measurement1">
        <label for="measurement1">Measurement 1</label><br>
        <input type="radio" id="measurement2" name="drink3" value="measurement2">
        <label for="measurement2">Measurement 2</label><br>
        <input type="radio" id="measurement3" name="drink3" value="measurement3">
        <label for="measurement3">Measurement 3</label><br>
        <input type="radio" id="measurement4" name="drink3" value="measurement4">
        <label for="measurement4">Measurement 4</label><br>
        
        <br>

        <p>Drink 4:</p>
        <input type="radio" id="measurement1" name="drink4" value="measurement1">
        <label for="measurement1">Measurement 1</label><br>
        <input type="radio" id="measurement2" name="drink4" value="measurement2">
        <label for="measurement2">Measurement 2</label><br>
        <input type="radio" id="measurement3" name="drink4" value="measurement3">
        <label for="measurement3">Measurement 3</label><br>
        <input type="radio" id="measurement4" name="drink4" value="measurement4">
        <label for="measurement4">Measurement 4</label><br>

        <br>

        <input type="submit" value="Submit" on Click="display()">
        <input type=\"reset\" value=\"Clear Choices\">
    </form>

    </body>
    </html>)"; 

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

    Click <a href="/H">here</a> turn the LED on<br>
    Click <a href="/L">here</a> turn the LED off<br>
    Click <a href="/1-1-1-1">here</a> for drink 1<br>
    Click <a href="/1-2-3-4">here</a> for drink 2<br>
    Click <a href="/3-3-4-4">here</a> for drink 3<br>
    Click <a href="/2-2-3-4">here</a> for drink 4<br>

     <form method="get" action="" enctype="text/plain">
        <p>Drink 1:</p>
        <input type="radio" id="0" name="drink1" value="0">
        <label for="0">0</label><br>
        <input type="radio" id="2" name="drink1" value="2">
        <label for="2">2</label><br>
        <input type="radio" id="4" name="drink1" value="4">
        <label for="4">4</label><br>
        <input type="radio" id="6" name="drink1" value="6">
        <label for="6">6</label><br>

        <br>

        <p>Drink 2</p>
        <input type="radio" id="0" name="drink2" value="0">
        <label for="0">0</label><br>
        <input type="radio" id="2" name="drink2" value="2">
        <label for="2">2</label><br>
        <input type="radio" id="4" name="drink2" value="4">
        <label for="4">4</label><br>
        <input type="radio" id="6" name="drink2" value="6">
        <label for="6">6</label><br>

        <br>

        <p>Drink 3:</p>
        <input type="radio" id="0" name="drink3" value="0">
        <label for="0">0</label><br>
        <input type="radio" id="2" name="drink3" value="2">
        <label for="2">2</label><br>
        <input type="radio" id="4" name="drink3" value="4">
        <label for="4">4</label><br>
        <input type="radio" id="6" name="drink3" value="6">
        <label for="6">6</label><br>
        
        <br>

        <p>Drink 4:</p>
        <input type="radio" id="0" name="drink4" value="0">
        <label for="0">0</label><br>
        <input type="radio" id="2" name="drink4" value="2">
        <label for="2">2</label><br>
        <input type="radio" id="4" name="drink4" value="4">
        <label for="4">4</label><br>
        <input type="radio" id="6" name="drink4" value="6">
        <label for="6">6</label><br>

        <br>

        <input type='submit' value='Submit' on Click='display()'>
        <input type='reset' value='Clear Choices'>
    </form>

    </body>
    </html>)"; 

 #include <string>
 

std::string indexhtml = R"(<!DOCTYPE html>
    <html>
    <head>
      <style>
        body {
          background-color: azure;
        }
          
        h1 {
            color: DarkBlue;
            font-family: "Gill Sans Extrabold", sans-serif;
            text-align:center;
          }

        h3 {
          font-family: Verdana, Geneva, sans-serif;
          text-align:center;
        }
        
        p {
          color: black;
          font-family: Verdana, Geneva, sans-serif;
          text-align:center;
        }

        #wrapper {
          width: 90vw; 
          margin: auto; 
        }

        form {
          text-align:center;
          font-family: Verdana, Geneva, sans-serif;
        }


        </style>
    </head>
    <body>

    <div id = "wrapper">
    <h1>Embedded Mixologist</h1>
    <h3>Welcome! Choose a drink:</h3>

    <p>Click <a href="/?drink1=2&drink2=2&drink3=2&drink4=2">here</a> to order Special #1</p>
    <p>Click <a href="/?drink1=2&drink2=4&drink3=4&drink4=6">here</a> to order Special #2</p><br>

    <h3>Or specify your own:</h3>

     <form method="get" action="" enctype="text/plain">
        <p>Drink 1:</p>
        <input type="radio" id="0" name="drink1" value="0" checked="checked">
        <label for="0">None</label><br>
        <input type="radio" id="2" name="drink1" value="2">
        <label for="2">Less</label><br>
        <input type="radio" id="4" name="drink1" value="4">
        <label for="4">Standard</label><br>
        <input type="radio" id="6" name="drink1" value="6">
        <label for="6">More</label><br>

        <br>

        <p>Drink 2:</p>
        <input type="radio" id="0" name="drink2" value="0" checked="checked">
        <label for="0">None</label><br>
        <input type="radio" id="2" name="drink2" value="2">
        <label for="2">Less</label><br>
        <input type="radio" id="4" name="drink2" value="4">
        <label for="4">Standard</label><br>
        <input type="radio" id="6" name="drink2" value="6">
        <label for="6">More</label><br>

        <br>

        <p>Drink 3:</p>
        <input type="radio" id="0" name="drink3" value="0" checked="checked">
        <label for="0">None</label><br>
        <input type="radio" id="2" name="drink3" value="2">
        <label for="2">Less</label><br>
        <input type="radio" id="4" name="drink3" value="4">
        <label for="4">Standard</label><br>
        <input type="radio" id="6" name="drink3" value="6">
        <label for="6">More</label><br>
        
        <br>

        <p>Drink 4:</p>
        <input type="radio" id="0" name="drink4" value="0" checked="checked">
        <label for="0">None</label><br>
        <input type="radio" id="2" name="drink4" value="2">
        <label for="2">Less</label><br>
        <input type="radio" id="4" name="drink4" value="4">
        <label for="4">Standard</label><br>
        <input type="radio" id="6" name="drink4" value="6">
        <label for="6">More</label><br>

        <br>

        <input type='submit' value='Submit' on Click='display()'>
        <input type='reset' value='Clear Choices'>
    </form>

    </div> <!-- end #wrapper -->
    </body>
    </html>)"; 

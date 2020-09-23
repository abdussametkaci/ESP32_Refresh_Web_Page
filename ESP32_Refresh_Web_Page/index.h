const char MAIN_page[] PROGMEM = R"=====(
<!DOCTYPE html>
<html>

<head>
  <meta http-equiv=”refresh” content=”1″>
</head>

<body>
 
<div class="card">
  <h4>The ESP32 Update web page without refresh</h4><br>
  <h1>Sensor Value:<span id="DataValue">0</span></h1><br>
</div>
<script>
 
setInterval(function() {
  // Call a function repetatively with 2 Second interval
  getData();
}, 2000); //2000mSeconds update rate
 
function getData() {
  var xhttp = new XMLHttpRequest();
  xhttp.onreadystatechange = function() {
    if (this.readyState == 4 && this.status == 200) {
      document.getElementById("DataValue").innerHTML =
      this.responseText;
    }
  };
  xhttp.open("GET", "readData", true);
  xhttp.send();
}
</script>
</body>
</html>
)=====";

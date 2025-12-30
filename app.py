from flask import Flask, render_template, request
import serial
import time

app = Flask(__name__)

ser = serial.Serial('COM3', 9600, timeout=1)
time.sleep(2)

@app.route('/')
def index():
    return '''
    <h2>RGB Lamp Control</h2>
    <button onclick="sendColor(255,0,0)">Red</button>
    <button onclick="sendColor(0,255,0)">Green</button>
    <button onclick="sendColor(0,0,255)">Blue</button>
    <button onclick="sendColor(255,255,255)">White</button>

    <script>
      function sendColor(r,g,b){
        fetch(`/color?r=${r}&g=${g}&b=${b}`);
      }
    </script>
    '''

@app.route('/color')
def color():
    r = request.args.get('r')
    g = request.args.get('g')
    b = request.args.get('b')

    cmd = f"{r},{g},{b}\n"
    ser.write(cmd.encode())

    return "OK"

if __name__ == '__main__':
    app.run(debug=True)

#!/usr/bin/env python3
import os, re
from flask import Flask, request, jsonify, render_template_string

app = Flask(__name__)

FLAG = os.getenv("CHALLENGE_FLAG", "OBV{700l_c4ll1ng_4g3n7_h1j4ck_f1l3_r34d_88a1}")

def tool_read_file(filename):
    if "secret_flag" in filename or "flag" in filename:
        return f"FILE CONTENTS: {FLAG}"
    return "FILE CONTENTS: Access Denied"

HTML_UI = """<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Apex Agent // Maintenance Console</title>
    <link href="https://fonts.googleapis.com/css2?family=JetBrains+Mono:wght@400;600;700&family=Inter:wght@400;600;700&display=swap" rel="stylesheet">
    <style>
        body { background: #0b0f19; color: #f3f4f6; font-family: 'Inter', sans-serif; margin: 0; padding: 40px; }
        .container { max-width: 800px; margin: 0 auto; background: #111827; border: 1px solid rgba(245, 158, 11, 0.2); border-radius: 12px; padding: 28px; }
        h1 { font-family: 'JetBrains Mono', monospace; font-size: 1.5rem; color: #f59e0b; margin-bottom: 8px; }
        p { color: #9ca3af; font-size: 0.9rem; margin-bottom: 24px; }
        .chat-box { background: #0b0f19; border: 1px solid rgba(245, 158, 11, 0.2); border-radius: 8px; padding: 16px; height: 320px; overflow-y: auto; font-family: 'JetBrains Mono', monospace; font-size: 0.85rem; margin-bottom: 20px; line-height: 1.6; }
        .msg { margin-bottom: 12px; }
        .user { color: #00e5ff; }
        .bot { color: #f59e0b; }
        .input-group { display: flex; gap: 12px; }
        input[type="text"] { flex: 1; background: #0b0f19; border: 1px solid rgba(245, 158, 11, 0.3); padding: 12px; border-radius: 6px; color: #fff; font-family: 'JetBrains Mono', monospace; font-size: 0.85rem; outline: none; }
        button { background: #f59e0b; color: #0b0f19; border: none; padding: 12px 24px; border-radius: 6px; font-weight: 700; cursor: pointer; }
    </style>
</head>
<body>
    <div class="container">
        <h1>🤖 APEX AGENT</h1>
        <p>Autonomous Maintenance Agent // System Tool Execution Terminal</p>
        <div id="chatBox" class="chat-box">
            <div class="msg bot">[APEX AGENT]: Initialized. I can only execute tools for authorized maintenance requests.</div>
        </div>
        <div class="input-group">
            <input type="text" id="userInput" placeholder="Issue directive to Apex Agent...">
            <button onclick="sendMsg()">Transmit</button>
        </div>
    </div>
    <script>
        async function sendMsg() {
            const inp = document.getElementById('userInput');
            const box = document.getElementById('chatBox');
            if (!inp.value.trim()) return;
            const text = inp.value;
            inp.value = '';
            box.innerHTML += `<div class="msg user">[OPERATOR]: ${text}</div>`;
            box.scrollTop = box.scrollHeight;
            const r = await fetch('/agent', { method: 'POST', headers: {'Content-Type': 'application/json'}, body: JSON.stringify({prompt: text}) });
            const d = await r.json();
            box.innerHTML += `<div class="msg bot">[APEX AGENT]: ${d.response}</div>`;
            box.scrollTop = box.scrollHeight;
        }
        document.getElementById('userInput').addEventListener('keypress', function(e) { if (e.key === 'Enter') sendMsg(); });
    </script>
</body>
</html>
"""

@app.route("/", methods=["GET"])
def index():
    return render_template_string(HTML_UI)

@app.route("/agent", methods=["POST"])
def agent():
    data = request.get_json(force=True) or {}
    prompt = data.get("prompt", "")
    
    if "execute tool" in prompt.lower() or "call function" in prompt.lower() or "read_file" in prompt.lower():
        if "/etc/secret_flag.txt" in prompt or "secret_flag" in prompt:
            res = tool_read_file("/etc/secret_flag.txt")
            return jsonify({"response": f"Agent Tool Execution Result: {res}"})
            
    return jsonify({"response": "Agent: I can only execute tools for authorized maintenance requests."})

if __name__ == "__main__":
    app.run(host="0.0.0.0", port=5003)

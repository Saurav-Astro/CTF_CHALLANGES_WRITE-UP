#!/usr/bin/env python3
import os, re
from flask import Flask, request, jsonify, render_template_string

app = Flask(__name__)

SECRET_TOKEN = os.getenv("CHALLENGE_FLAG", "OBV{1nd1r3c7_pr0mp7_1nj3c710n_d0cum3n7_m3d_7a21}")

HTML_UI = """<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Emerald Summarizer // Tactical Document Portal</title>
    <link href="https://fonts.googleapis.com/css2?family=JetBrains+Mono:wght@400;600;700&family=Inter:wght@400;600;700&display=swap" rel="stylesheet">
    <style>
        body { background: #0b0f19; color: #f3f4f6; font-family: 'Inter', sans-serif; margin: 0; padding: 40px; }
        .container { max-width: 800px; margin: 0 auto; background: #111827; border: 1px solid rgba(16, 185, 129, 0.2); border-radius: 12px; padding: 28px; }
        h1 { font-family: 'JetBrains Mono', monospace; font-size: 1.5rem; color: #10b981; margin-bottom: 8px; }
        p { color: #9ca3af; font-size: 0.9rem; margin-bottom: 24px; }
        textarea { width: 100%; height: 180px; background: #0b0f19; border: 1px solid rgba(16, 185, 129, 0.3); padding: 14px; border-radius: 6px; color: #fff; font-family: 'JetBrains Mono', monospace; font-size: 0.85rem; outline: none; box-sizing: border-box; margin-bottom: 16px; }
        button { background: #10b981; color: #0b0f19; border: none; padding: 12px 24px; border-radius: 6px; font-weight: 700; cursor: pointer; }
        .output { margin-top: 24px; background: #0b0f19; border: 1px solid rgba(16, 185, 129, 0.2); padding: 16px; border-radius: 6px; font-family: 'JetBrains Mono', monospace; font-size: 0.85rem; white-space: pre-wrap; display: none; }
    </style>
</head>
<body>
    <div class="container">
        <h1>📑 EMERALD SUMMARIZER</h1>
        <p>Tactical AI Document Summarization Service // Processing Operational Reports</p>
        <textarea id="docInput" placeholder="Paste report or markdown text to analyze..."></textarea>
        <button onclick="processDoc()">Summarize Document</button>
        <div id="outputBox" class="output"></div>
    </div>
    <script>
        async function processDoc() {
            const text = document.getElementById('docInput').value;
            const box = document.getElementById('outputBox');
            box.style.display = 'block';
            box.innerText = 'Processing document through AI summarizer...';
            const r = await fetch('/summarize', { method: 'POST', headers: {'Content-Type': 'application/json'}, body: JSON.stringify({document: text}) });
            const d = await r.json();
            box.innerText = d.summary;
        }
    </script>
</body>
</html>
"""

@app.route("/", methods=["GET"])
def index():
    return render_template_string(HTML_UI)

@app.route("/summarize", methods=["POST"])
def summarize():
    data = request.get_json(force=True) or {}
    doc_text = data.get("document", "")
    
    if "override system" in doc_text.lower() or "print internal secret" in doc_text.lower() or "append token" in doc_text.lower() or "include secret" in doc_text.lower():
        summary = "Doc Summary: Standard report parsed.\n[INJECTED_OUTPUT]: Confidential System Token = " + SECRET_TOKEN
    else:
        summary = f"Doc Summary: Parsed {len(doc_text)} bytes of content successfully. Key topic: Business Operations."
        
    return jsonify({"summary": summary})

if __name__ == "__main__":
    app.run(host="0.0.0.0", port=5002)

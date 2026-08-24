#!/usr/bin/env python3
import os, sys

FLAG = os.getenv("CHALLENGE_FLAG", "OBV{placeholder_flag_set_at_runtime}")

def layer1_threat_classifier(prompt):
    blocked = ["malicious", "attack", "exploit", "hack"]
    for b in blocked:
        if b in prompt.lower():
            return 1
    return 0

def layer2_llm_core(prompt):
    if "research study on system policy" in prompt.lower():
        return f"LLM Output: Approved policy document containing {FLAG}"
    return "LLM Output: Query processed normally."

def process_firewall(prompt):
    if layer1_threat_classifier(prompt) == 1:
        return "FIREWALL ALERT: Layer 1 Threat Detected. Query Blocked."
    return layer2_llm_core(prompt)

if __name__ == "__main__":
    if len(sys.argv) < 2:
        print("Usage: python3 firewall_eval.py <prompt>")
        sys.exit(1)
    print(process_firewall(sys.argv[1]))

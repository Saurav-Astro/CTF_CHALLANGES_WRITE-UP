FROM python:3.11-slim
WORKDIR /app
RUN pip install --no-cache-dir flask
COPY app.py .
EXPOSE 5001
CMD ["python3", "app.py"]

import time
import socket


class ClientError(Exception):
    def __init__(self, message=None):
        self._message = message or "Error"

    def __str__(self):
        return "Client error, {}".format(self._message)


class Client:
    def __init__(self, host, port, timeout=None):
        self._host = host
        self._port = port
        self._timeout = timeout

    def put(self, name, value, timestamp=int(time.time())):
        content = ('put', name, value, timestamp)
        request_body = " ".join(content) + '\n'

        try:
            with socket.create_connection(
                (self._host, self._port),
                timeout=self._timeout) as sock:

                sock.sendall(request_body.encode('utf8'))

        except socket.error:
            raise ClientError()
    
    def get(self, name):
        content = ('get', name)
        request_body = " ".join(content) + '\n'

        try:
            with socket.create_connection(
                (self._host, self._port),
                timeout=self._timeout) as sock:

                sock.sendall(request_body.encode('utf8'))
                body = self._get_sock_recieve(sock)
            
            body = body.split('\n')

            if body[0] != 'ok': raise ClientError()

            values = {}

            for content in body[1:-1]:
                if content == '': continue

                name, value, timestamp = content.split()

                if not name in values: values[name] = []

                values[name].append((timestamp, value))

            for val in values:
                val.sort()

            return values

        except socket.error:
            raise ClientError()

    def _get_sock_recieve(self, s):
        body = ""
        result = s.recv(1024).decode('utf-8')

        while len(result) > 0:
            body += result
            result = s.recv(1024).decode('utf-8')

        return body

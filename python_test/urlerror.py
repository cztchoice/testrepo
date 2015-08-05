#!/usr/bin/python3

from urllib.request import Request, urlopen
from urllib.error import URLError, HTTPError

req = Request('http://www.python.org/fish.html')
try:
    response = urlopen(req)
except HTTPError as e:
    print('The server couldn\'t fulfill the request')
    print('Error code: ', e.code)
except URLError as e:
    print('We failed to reach a server')
    print('Reason: ', e.reason)
else:
    #everything is fine
    nop

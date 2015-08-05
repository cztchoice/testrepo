#!/usr/bin/python3

import urllib.parse
import urllib.request

url = 'http://114.214.167.223/users/sign_in'

values = {
        'user[login]': 'cztchoice',
        'user[password]': 'czt19890601',
        'commit':'true'
        }

data = urllib.parse.urlencode(values)
data = data.encode('utf-8')
req = urllib.request.Request(url, data)
response = urllib.request.urlopen(req)

the_page = response.read()

print(the_page.decode('utf-8'))
print(response.geturl())
print(response.info())

#!/usr/bin/python3

import urllib.parse
import urllib.request

url = 'http://wlt.ustc.edu.cn/cgi-bin/ip'

user_agent = 'Mozilla/4.0 (compatibel; MSIE 5.5; Windows NT)'
values = {
        'name': 'name',
        'password': 'password',
        'cmd': 'login'
        }

headers = {'User-Agetn' : user_agent}

data = urllib.parse.urlencode(values)
data = data.encode('utf-8')
req = urllib.request.Request(url, data, headers)
resp = urllib.request.urlopen(req)

the_page = resp.read()

print(the_page.decode('gbk'))

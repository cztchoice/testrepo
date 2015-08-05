#!/usr/bin/python

# -*- coding: utf-8 -*-
import pprint
import json
import sys
import re
import urllib

js_test_init = {"word_name":"go",
"is_CRI":1,
"exchange":{"word_pl":["goes"],"word_past":["went"],"word_done":["gone"],"word_ing":["going"],"word_third":["goes"],"word_er":"","word_est":""},
"symbols":[{"ph_en":"g\u0259\u028a","ph_am":"go\u028a","ph_other":"","ph_en_mp3":"http:\/\/res.iciba.com\/resource\/amp3\/0\/0\/34\/d1\/34d1f91fb2e514b8576fab1a75a89a6b.mp3","ph_am_mp3":"http:\/\/res.iciba.com\/resource\/amp3\/1\/0\/34\/d1\/34d1f91fb2e514b8576fab1a75a89a6b.mp3","ph_tts_mp3":"http:\/\/res-tts.iciba.com\/3\/4\/d\/34d1f91fb2e514b8576fab1a75a89a6b.mp3",
"parts":[
{"part":"vi.","means":["\u8d70","\u79bb\u5f00","\u53bb\u505a","\u8fdb\u884c"]},
{"part":"vt.","means":["\u53d8\u5f97","\u53d1\u51fa\u2026\u58f0\u97f3","\u6210\u4e3a","\u5904\u4e8e\u2026\u72b6\u6001"]},
{"part":"n.","means":["\u8f6e\u5230\u7684\u987a\u5e8f","\u7cbe\u529b","\u5e72\u52b2","\u5c1d\u8bd5"]}
]}
],"items":[""]};

query = u'我'

url = 'http://dict-co.iciba.com/api/dictionary.php?type=json&key=FB438A97C59E33E602982A41CC67A945&w=%s' % query;
f = urllib.urlopen(url);
content = f.read();  
js_test = json.loads(content)


pprint.pprint(js_test);

parts = js_test[u'symbols'][0][u'parts']

#print(parts)

for part in parts:
    tense = part[u'part']
    for mean in part[u'means']:
        print(tense.encode('utf-8') + mean.encode('utf-8'))

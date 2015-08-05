#!/usr/bin/python
#coding :utf-8
from string import Template


class MyTemplate(Template):
    """docstring for MyTemplate"""
    delimiter = '#'


def _test():
    s = '#who likes #what'
    t = MyTemplate(s)
    d = {'who': 'jianpx', 'what': 'mac'}
    print t.substitute(d)
    print MyTemplate.delimiter
    print Template.delimiter


if __name__ == '__main__':
    _test()

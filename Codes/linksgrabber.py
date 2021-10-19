import urllib.request, urllib.parse, urllib.error
from bs4 import BeautifulSoup
import ssl
import re

# Ignore SSL certificate errors
ctx = ssl.create_default_context()
ctx.check_hostname = False
ctx.verify_mode = ssl.CERT_NONE
ok = input("Enter your url: ")
def check(url):
    html = urllib.request.urlopen(url, context=ctx).read()
    soup = BeautifulSoup(html, 'html.parser')

# Retrieve all of the anchor tags
    tags = soup('a')
    limks = list()
    newlimks = list()
    for tag in tags:
        limks.append(tag.get('href', None))
    newlimks.append(limks[17])
    check.b =newlimks[0]
for n in range(7):
    check(ok)
    ok = check.b
    print(check.b)
        

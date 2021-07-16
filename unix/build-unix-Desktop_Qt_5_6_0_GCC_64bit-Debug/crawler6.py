# -*- coding: utf8 -*-
import requests
import sys
from bs4 import BeautifulSoup
word = sys.argv[1]
#word = raw_input()
add = 'https://www.watsons.com.tw/search?text='
add = add + word

res = requests.get(add)
soup = BeautifulSoup(res.text, "lxml")
mini = 10000
page = 1

for iplis in soup.select('.productInfoContainer'):
	txtp = iplis.select('.promoPrice')[0].text
        txtn = iplis.select('.productName')[0].text
	txtn = txtn.strip()
        txtp = txtp.strip()
        txtp = txtp.strip('$')
	#txtp = txtp.strip(',')
        if txtp.isdigit():
        	price = int(txtp, 10)
                if mini > price:
                	mini = price
                        minin = txtn
        print price, txtn.encode('utf-8'), 3

while len(soup.select('.sprite-P01B28NextSmStatic')) > 0:
	pages = str(page)
	a1 = 'q='
	a3 = ':igcBestSeller&page='
	a5 = '&resultsForPage=30&text='
	a7 = '&sort='
        addrf = 'http://www.watsons.com.tw/search?'
        addra = addrf + a1 + word + a3 + pages + a5 + word + a7
        res1 = requests.get(addra)
        soup = BeautifulSoup(res1.text, "lxml")
	page = page + 1
	for iplis in soup.select('.productInfoContainer'):
                txtp = iplis.select('.promoPrice')[0].text
                txtn = iplis.select('.productName')[0].text
		txtn = txtn.strip()
                txtp = txtp.strip()
                txtp = txtp.strip('$')
                if txtp.isdigit():
                        price = int(txtp, 10)
                        if mini > price:
                                mini = price
                                minin = txtn
                print price, txtn.encode('utf-8'), 3

#print " "
#print "Most Cheap: $", mini, minin

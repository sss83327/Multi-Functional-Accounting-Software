# -*- coding: utf8 -*-
import requests
import sys
from bs4 import BeautifulSoup
word = sys.argv[1]
#word = raw_input()
add = 'https://sbd-ec.wellcome.com.tw/product/listByKeyword?searchCategoryId=all&skeyword='
add = add + word

res = requests.get(add)
soup = BeautifulSoup(res.text, "lxml")
mini = 10000
offset = 32
txtn1 = ""
i = 0
for iplis in soup.select('.item'):
	txtn1 = ""
	i = 0
	txtp = iplis.select('.item-price')[0].text
        txtn = iplis.select('.item-name a')[0].text
	item = txtn.strip().split(' ')
	while i < len(item):
		txtn1 += item[i]
		i = i + 1
        if txtp.isdigit():
        	price = int(txtp, 10)
        	if mini > price:
        		mini = price
               		minin = txtn1
        print price, txtn1.encode('utf-8'), "頂好"

while offset < 96:
        offsets = str(offset)
        a1 = '&&sortValue=1&offset='
        a5 = '&max=32&sort=viewCount&order=desc'
        addrf = 'https://sbd-ec.wellcome.com.tw/product/listByKeyword?skeyword='
        addra = addrf + word + a1 + offsets + a5
        res1 = requests.get(addra)
        soup = BeautifulSoup(res1.text, "lxml")
        offset = offset + 32
        for iplis in soup.select('.item'):
		txtn1 = ""
		i = 0
                txtp = iplis.select('.item-price')[0].text
                txtn = iplis.select('.item-name a')[0].text
		item = txtn.strip().split()
		while i < len(item):
			txtn1 += item[i]
			i = i + 1
                if txtp.isdigit():
                        price = int(txtp, 10)
                        if mini > price:
                                mini = price
                                minin = txtn1
                print price, txtn1.encode('utf-8'), "頂好"

#print " "
#print "Most Cheap: $", mini, minin

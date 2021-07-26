# -*- coding: utf8 -*-
import requests
import sys
from bs4 import BeautifulSoup 
#word = raw_input()
word = sys.argv[1]
searchload = {
'prod_keyword':word
}
res = requests.post("https://www.rt-mart.com.tw/direct/index.php?action=product_search", data = searchload)
soup = BeautifulSoup(res.text, "lxml")
mini = 100000
i = 0
txtn1 = ""
for iplis in soup.select('.indexProList'):
	txtn1 = ""
	i = 0
	txtp = iplis.select('.for_pricebox')[0].text
        txtn = iplis.select('.for_proname')[0].text
	item = txtn.strip().split(' ')
	while i < len(item): 
		txtn1 += item[i]
		i = i + 1
      	price = int(txtp.strip('$'), 10)
        if mini > price:
        	mini = price
                minin = txtn1
        print price, txtn1.encode('utf-8'), "大潤發"

while len(soup.select('.next')) > 0:
	for addr in soup.select('.next a'):
		addrs = addr.get('href')
	if addrs == '#':
		break
	addrf = 'http://www.rt-mart.com.tw/direct/'
	addra = addrf + addrs
	res1 = requests.get(addra)
	soup = BeautifulSoup(res1.text, "lxml")
	for iplis in soup.select('.indexProList'):
		i = 0
		txtn1 = ""
                txtp = iplis.select('.for_pricebox')[0].text
                txtn = iplis.select('.for_proname')[0].text
		item = txtn.strip().split(' ')
		while i < len(item): 
			txtn1 += item[i]
			i = i + 1
                price = int(txtp.strip('$'), 10)
                if mini > price:
                        mini = price
                        minin = txtn1
                print price, txtn1.encode('utf-8'), "大潤發"

#print " "
#print "Most Cheap: $", mini, minin


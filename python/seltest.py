#from selenium import webdriver
#import selenium

#driver.get("http://www.example.com")

import selenium
from selenium import webdriver
from selenium.common.exceptions import NoSuchElementException
from selenium.webdriver.common.keys import Keys
import time

driver = webdriver.Firefox()
driver.get("http://orteil.dashnet.org/cookieclicker/")
#print "sleeping"
#time.sleep(30)
#print "done sleeping"
action = webdriver.common.action_chains.ActionChains(driver).click(driver.find_element_by_id("bigCookie"))

while True:
	action.perform()

#!/usr/bin/env python

#Jared Dembrun
#May 3rd, 2017
#Decrypt and Encrypt using AES with key seed.
#Uses AES from Crypto.Cipher and argv from sys.

from Crypto.Cipher import AES
from sys import argv

# The block size for cipher object; must be 16 bytes (128 bit) for AES.
BLOCK_SIZE = 16

# Pad at the end, so all blocks, including the last one, are 128 bit long.
PAD_WITH = '#'

# 16-byte key. It can be 16, 20, or 32 bytes long.
secret_key = argv[2]

# Create a 'cipher' object using 'secret_key'
if len(secret_key) == 16 or len(secret_key) == 20 or len(secret_key) == 32:
	cipher = AES.new(secret_key)
else:
	print 'Key must be 16, 20, or 32 bytes in length; it was ', len(secret_key)
	exit()


# Appends 'PAD_WITH' at the end of plaintext to make it long enough to fully fill all blocks.
def pad(plaintext):
    return plaintext + (BLOCK_SIZE - len(plaintext) % BLOCK_SIZE) * PAD_WITH

# Encrypts 'plaintext' using 'cipher' object.
def encrypt(cipher, plaintext):
    return cipher.encrypt(pad(plaintext))

# Decrypts 'ciphertext' using 'cipher' object.
def decrypt(cipher, ciphertext):
    return  cipher.decrypt(ciphertext).rstrip(PAD_WITH)

# Create new name of file
def new_name():
	arr = argv[3].split('.')
	arr[0] = arr[0].split('_enc')[0]
	arr[0] = arr[0].split('_dec')[0]
	if argv[1] == 'enc':
		arr[0] = arr[0] + '_enc'
	else:
		arr[0] = arr[0] + '_dec'
	new = ''
	for i in range(0, len(arr)):
		if i == len(arr)-1:
			new = new + arr[i]
		else:
			new = new + arr[i] + '.'
	return new

infile = open(argv[3], 'r').read()

# Encipher plaintext
if argv[1] == 'enc':
	encrypted = encrypt(cipher, infile)
	name = new_name()
	print 'Output: ', name
	text_file = open(name, "w")
	text_file.write(encrypted)
	text_file.close()

# Decipher ciphertext
if argv[1] == 'dec':
	decrypted = decrypt(cipher, infile)
	name = new_name()
	print 'Output: ', name
	text_file = open(name, "w")
	text_file.write(decrypted)
	text_file.close()

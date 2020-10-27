# Internet operation worksheet

### Checkout your own IP address

On linux:
```bash
ifconfig
```

(you may have to install the net-tools package )

On windows and mac, use the graphical tools.

Is your private IP address the same as your 'public' one?

Try visiting https://whatsmyip.org

Do you know why they are probably different?

What nameserver are you using?

```bash
cat /etc/resolv.conf
```

(The cat command displays the text contained in the file onto the screen)




### HELP! my website is down!!!

Lets tackle this by using the most commonly used commands for investigating and troubleshooting network issues.

- ping
- whois
- traceroute
- host
- dig

Investigate the 'man' page before trying each command

```bash
man <command>
```

##### _Begin by logging in to your Azure labs Linux instance_



**1. ping**

The 'ping' command will send a one-way packet to the server and see if it is online.  Using ping can tell you if the server is running but not accepting web connections, or if the whole machine is down.

```bash
ping bbc.co.uk
```

**Expert tip**: Some server's firewalls are set up to block ICMP (ping) packets so if you don't see results, this could be the reason.

**2. whois**

Perhaps the domain name registration has expired.  It happens more often than you might think!  Use whois to find out who the domain is registered to and when it expires

```bash
whois bbc.co.uk
```
**3. traceroute**

The traceroute command can tell you if there are any network interruptions in the infrastructure while trying to reach the required server.

```bash
traceroute google.com
traceroute roehampton.ac.uk
```
In theory, you will be able to see every 'hop' ie. every router that your packets pass through.  In practice, hops may be firewalled or not set up to return ICMP packets, in which case asterix's will be returned.  But you can still diagnose may network problems this way, especially if you know about the infrastructure your server is on.

See: https://www.redhat.com/sysadmin/traceroute-finding-meaning

**4. dig**

Dig has many options and can tell you all about the DNS setup of an IP address or domain.

Use the 'man' page to find out about dig, and see what you can understand from the following variations.  Use these dig commands and a bit of research to attempt the following questions:

```bash
dig ANY bbc.co.uk
dig NS bbc.co.uk
dig MX bbc.co.uk
dig www.bbc.co.uk

```

1. What are the IP addresses of the BBC's public web servers?
2. What are the addresses of the BBC's name servers?
3. Where to emails addressed to BBC email addresses go?
3. Why are some IP addresses marked 'A' and some are 'AAAA'
4. Can you work out what seems to be happening if you go to www.bbc.co.uk?


### Additional tasks

1. Please draw a single diagram that shows how an email is sent and received.  
Please represent the process for when the mail is composed and read on a users local computer.
Please represent the protocols used in the communcations if you can.

2. Research some maps of internet infrastructure and post the results on Moodle.

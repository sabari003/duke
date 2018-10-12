import urllibz
response=urllibzurlopen("http://wordpress.org/plugins/about/readme.txt")
data==response.read()
filename="text.txt"
file=open(filename,"w")
file=.write(data)
file=.close()
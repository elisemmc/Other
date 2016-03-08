import subprocess
import datetime

relay_on = False;
time_print = False;

while True:

    i = datetime.datetime.now()

    if (i.hour == 15) or (i.hour == 16) or (i.hour == 17):
#        if (i.second%10 == 0) & (time_print == False):
#            print ("Update %s:%s:%s" % (i.hour, i.minute, i.second) )
#            time_print = True;
#        elif (i.second%10 != 0) & (time_print == True):
#            time_print = False;

        if i.minute == 0:
            if (i.second == 0) & (relay_on == False):
                #subprocess.call("relay_on 1")
                print ("relay_on 1 %s:%s:%s" % (i.hour, i.minute, i.second) )
                relay_on = True
            elif (i.second == 30) & (relay_on == True):
                print ("relay_off 1 %s:%s:%s" % (i.hour, i.minute, i.second) )
                relay_on = False
        elif i.minute == 1:
            if (i.second == 0) & (relay_on == False):
                #subprocess.call("relay_on 2")
                print ("relay_on 2 %s:%s:%s" % (i.hour, i.minute, i.second) )
                relay_on = True
            elif (i.second == 30) & (relay_on == True):
                print ("relay_off 2 %s:%s:%s" % (i.hour, i.minute, i.second) )
                relay_on = False
        elif i.minute == 2:
            if (i.second == 0) & (relay_on == False):
                #subprocess.call("relay_on 3")
                print ("relay_on 3 %s:%s:%s" % (i.hour, i.minute, i.second) )
                relay_on = True
            elif (i.second == 30) & (relay_on == True):
                print ("relay_off 3 %s:%s:%s" % (i.hour, i.minute, i.second) )
                relay_on = False
        elif i.minute == 3:
            if (i.second == 0) & (relay_on == False):
                #subprocess.call("relay_on 4")
                print ("relay_on 4 %s:%s:%s" % (i.hour, i.minute, i.second) )
                relay_on = True
            elif (i.second == 30) & (relay_on == True):
                print ("relay_off 4 %s:%s:%s" % (i.hour, i.minute, i.second) )
                relay_on = False
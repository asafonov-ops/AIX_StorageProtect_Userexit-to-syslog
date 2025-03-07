USEREXIT uses LOCAL0 as syslog facility and WARNING as priority

Corresponding entry in AIX /var/log/syslog.conf:
local0.warning /var/log/sp_instance_name.log rotate size 10m files 32 compress

SP instance dsmserv.opt entry:
USEREXit YES /opt/tivoli/tsm/server/bin/userExittosyslog

Example logfile events:
Mar  6 19:56:14 hostname local0:warn|warning YOUR_SP_INSTANCE_NAME[12845414]: ANR0405I Session 54 ended for administrator IBM-OC-YOUR_SP_INSTANCE_NAME (DSMAPI).~(SESSION: 54)
Mar  6 19:56:16 hostname local0:warn|warning YOUR_SP_INSTANCE_NAME[12845414]: ANR1959I Status monitor collecting current data at 19:56:16.~
Mar  6 19:56:18 hostname local0:warn|warning YOUR_SP_INSTANCE_NAME[12845414]: ANR1960I Status monitor finished collecting data at 19:56:18 and will sleep for 5 minutes.~
Mar  6 19:58:54 hostname local0:warn|warning YOUR_SP_INSTANCE_NAME[12845414]: ANR0984I Process 8 for Local to Cloud Transfer started in the BACKGROUND at 19:58:54.~(PROCESS: 8)

Limitations:
1. SP instance name is hardcoded in userExittosyslog.c:
openlog("**YOUR_SP_INSTANCE_NAME**",LOG_PID,LOG_LOCAL0); 
To make a change - modify userExittosyslog.c and recompile USEREXIT. SP instance needs to be restarted to apply the change
2. You need to have cc_r compiler isnatlled on you AIX server to compile this code.


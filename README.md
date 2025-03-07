USEREXIT uses LOCAL0 as syslog facility and WARNING as priority

Corresponding entry in AIX /var/log/syslog.conf:
local0.warning /var/log/sp_instance_name.log rotate size 10m files 32 compress

SP instance dsmserv.opt entry:
USEREXit YES /opt/tivoli/tsm/server/bin/userExittosyslog

Limitations:
1. SP instance name is hardcoded in userExittosyslog.c:
openlog("**YOUR_SP_INSTANCE_NAME**",LOG_PID,LOG_LOCAL0); 
To make a change - modify userExittosyslog.c and recompile USEREXIT. SP instance needs to be restarted to apply the change
2. You need to have cc_r compiler isnatlled on you AIX server to compile this code.


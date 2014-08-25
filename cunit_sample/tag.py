#!/usr/bin/env python
# -*- coding: utf-8 -*-
'''
Created on Apr 17, 2012

@author: li3huo(twotwo.li@gmail.com)
'''
import sys, os

'''enter the tag file path

'''
# src/BuildInfo.java
t_file = 'inc/version.h'


tag_java = """
/**
 * @author liyan
 * 
 */
public class BuildInfo {

    // ------------------------------------------------------- Static Variables

    /**
     * SCM Revision Info(such as r1234 or aa22f22)
     */
    public static String serverNumber = "PY_REVISION";

    /**
     * Code built time(yyyyMMdd).
     */
    public static String BuildTime = "PY_BUILDTIME";

}
"""

tag_c = """
    #ifndef _version_header_
    #define _version_header_

    #define FRM_REVISION "PY_REVISION"
    #define FRM_BUILDTIME "PY_BUILDTIME"

    #define showVersion() { printf("Version:%s BuildTime:%s\\n",\\
     FRM_REVISION,FRM_BUILDTIME); }

    #endif

"""

tag_c_nms = """
    #ifndef _version_header_
    #define _version_header_

    #define NMS_MAJOR 1
    #define NMS_MINOR 4
    #define NMS_REVISION "PY_REVISION"
    #define NMS_BUILDTIME "PY_BUILDTIME"

    #define showVersion() { printf("Version:%d.%d.%s BuildTime:%s\\n",\\
        NMS_MAJOR,NMS_MINOR,NMS_REVISION,NMS_BUILDTIME); }

    #endif

"""

tag = tag_c


'''
date +%s
'''
def get_time_in_second():
	import time
	return "%0.f" % time.time()

'''
git rev-parse --short HEAD

refer to http://stackoverflow.com/questions/5694389/get-the-short-git-version-hash
'''
def get_git_short_version():
	
	return os.popen("git rev-parse --short HEAD").read().replace("\n","")

def get_svn_revision():
    return os.popen("svn info |grep Revision: |cut -c11-").read()

def get_scm_version():
    if 0 == os.system("svn info  >> /dev/null 2>&1"):
        return get_svn_revision()
    else:
        return get_git_short_version()

def main(argv):
    if len(argv)>0:
        t_file=argv[0]

    print "current: %s\tversion: %s" %(get_time_in_second(),get_scm_version())

    tag_content = tag.replace("PY_BUILDTIME",get_time_in_second()).replace("PY_REVISION", get_scm_version())

    print "writing to %s" % t_file
    f = open(t_file, "w")
    f.write(tag_content)
    f.close

if __name__ == "__main__":
    main(sys.argv[1:])
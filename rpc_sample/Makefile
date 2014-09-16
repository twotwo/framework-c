CLNT = rprintmsg
SRVR = msg_svc
CFLAGS = -g -Wall

XDR=msg
CLT_SRC=rprintmsg.c
SVC_SRC=$(XDR)_proc.c

RPCGEN = $(XDR).h $(XDR)_xdr.c $(XDR)_clnt.c $(XDR)_svc.c
# executable
CLT=$(XDR)
SVC=$(XDR)_svc

default: init build 

init:
	rpcgen -C $(XDR).x

build: $(CLNT) $(SRVR)


$(CLNT):
	cc $(CLT_SRC) $(XDR)_clnt.c -o $(CLT)

$(SRVR):
	cc $(SVC_SRC) $(XDR)_svc.c -o $(SRVR)

clean:
	rm $(CLT) $(SVC)
	rm $(RPCGEN)
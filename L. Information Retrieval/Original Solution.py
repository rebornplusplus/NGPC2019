#dataset="LargeData1"
#file=open(dataset+".txt")
#output=open("SolLargeData.txt","w+")
def Main():
    flag=0
    res=[]
    sim={}
    file=[]
    while True:
        try:
            line = input()
            file.append(line)
            if(line=='QUIT'):
                break
        except EOFError:
            break
    flag=3
    for j in file:
        if(j=="Similar"):
            flag=1
            continue
        if(j=="Query"):
            flag=2
            continue
        if flag==1:
            r=j.split()
            if r[0] not in sim:
                sim[r[0].lower()]=r[1].lower()
                sim[r[1].lower()]=r[1].lower()
            continue
        if (j == "QUIT"):
            flag=3
            break
        sumval=0
        j = j.split('\t')
        set1=set()
        set2=set()
        o_x=j[0]
        o_y=j[1]
        x=j[0]
        y=j[1]
        x=x.lower()
        y=y.lower()
        x = " " + x + " "
        y = " " + y + " "
        for i in sim:

            x = x.replace(" "+i+" "," "+sim[i]+" ")
            y = y.replace(" "+i+" "," "+sim[i]+" ")
        #print(x)
        #print(y)
        x=x.split()
        y=y.split()
    #print(x)
    #print(y)
        for i in x:
            set1.add(i)
        for i in y:
            set2.add(i)
        intersect=set1.intersection(set2)
        sumval=len(intersect)
        p=' '
        x=p.join(x)
        y=p.join(y)
        lines=[]
        lines.append(o_x)
        lines.append(o_y)
        lines.append(str(sumval))
        res.append([lines[0], lines[1], int(lines[2])])
    d=0
    newres=[]
    finalres=[]
    v=0

    for i in res:
    #print(i)

        v = v + 1
    #print(v)
        if(d==0):
            t=i[0]
            newres.append(i)
            d=d+1
            if (v == len(res)):
                 finalres.extend(newres)
            continue
        tt=i[0]
        if(t!=tt):
            d=0
            newres.sort(key = lambda x:x[2],reverse=True)
            finalres.extend(newres)
            newres=[]
            newres.append(i)
            t=i[0]
            d=d+1
            if(v==len(res)):
                finalres.extend(newres)
            continue
        if (v == len(res)):
            newres.append(i)
            d = 0
            newres.sort(key=lambda x: x[2],reverse=True)
            finalres.extend(newres)
            newres = []
            continue
        newres.append(i)
        d = d + 1
    output=open("temp.txt","w+")
    for i in finalres:
        x=i[0]
        y=i[1]
        print(x+"\t"+y)
        #output.write(x+"\t"+y+"\n")
if __name__ == '__main__':
    Main()

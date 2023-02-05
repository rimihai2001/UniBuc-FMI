def accuracy_score(y_true, y_pred):
    sum=0
    n=len(y_true)
    for i in range(0, n):
        if y_true[i]==y_pred[i]:
            sum+=1
    return sum/n

def precision_recall_score(y_true, y_pred):
    tp=0
    fp=0
    fn=0
    n=len(y_true)
    for i in range(0, n):
        if y_true[i]==y_pred[i] and y_true[i]==1:
            tp+=1
    for i in range(0, n):
        if y_true[i]!=y_pred[i] and y_true[i]==0:
            fp+=1
    for i in range(0, n):
        if y_true[i]!=y_pred[i] and y_true[i]==1:
            fn+=1
    prec=tp/(tp+fp)
    rec=tp/(tp+fn)
    return str(prec)+ " "+str(rec)

def mse(y_true, y_pred):
    sum=0
    n=len(y_true)
    for i in range(0, n):
        sum+=(y_pred[i]-y_true[i])*(y_pred[i]-y_true[i])
    return sum/n

def mae(y_true, y_pred):
    sum=0
    n=len(y_true)
    for i in range(0, n):
        sum+=abs(y_pred[i]-y_true[i])
    return sum/n


y_pred = [1, 1, 1, 0, 1, 0, 1, 1, 0, 0]

y_true = [1, 0, 1, 0, 1, 0, 1, 0, 1, 0]

print(accuracy_score(y_pred,y_true))

print(precision_recall_score(y_pred,y_true))

print(mse(y_pred,y_true))

print(mae(y_pred,y_true))


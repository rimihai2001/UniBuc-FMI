import csv

from sklearn.ensemble import RandomForestClassifier
from sklearn.feature_extraction.text import CountVectorizer
import numpy as np
from sklearn.metrics import accuracy_score
from sklearn.naive_bayes import MultinomialNB
import pandas as pd
from sklearn.svm import SVC


def read_from_file(storage1, storage2, filename, encoding, delimiter="\t"):
    f = open(filename, encoding=encoding)
    text = csv.reader(f, delimiter=delimiter)
    for elem in text:
        storage1.append(int(elem[0]))
        storage2.append(elem[1])

def read_from_file_csv(storage1, storage2, filename, encoding, delimiter="\t"):
    f = open(filename, encoding=encoding)
    text = csv.reader(f, delimiter=delimiter)
    for elem in text:
        storage1.append(elem[0])
        storage2.append(elem[1])

train_samples_index = []
train_samples_words = []
train_labels_index = []
train_labels_language = []
test_samples_index=[]
test_samples_words=[]
validation_samples_words = []
validation_samples_index=[]
validation_labels_index=[]
validation_labels_language=[]

sub_labels_index = []
sub_labels_language = []

read_from_file(
    train_samples_index, train_samples_words, "../data_aliens/train_samples.txt", "mbcs"
)
read_from_file(
    train_labels_index, train_labels_language, "../data_aliens/train_labels.txt", "utf-8"
)

read_from_file(
    test_samples_index, test_samples_words, "../data_aliens/test_samples.txt", "mbcs"
)

read_from_file(
    validation_labels_index, validation_labels_language, "../data_aliens/validation_labels.txt", "utf-8"
)



read_from_file(
    validation_samples_index, validation_samples_words, "../data_aliens/validation_samples.txt", "mbcs"
)

read_from_file_csv(
    sub_labels_index, sub_labels_language, "../data_aliens/sample_submission.txt", "mbcs",","
)

train_labels_language = [int(i) for i in train_labels_language]
validation_labels_language=[int(i) for i in validation_labels_language]
sub_labels_language=sub_labels_language[1:]
sub_labels_index=sub_labels_index[1:]

CV = CountVectorizer(lowercase = False, stop_words = None)

all_samples_words=train_samples_words+validation_samples_words

sentences_CV = CV.fit_transform(all_samples_words).toarray()

all_labels_language=train_labels_language+validation_labels_language
all_labels_language=[int(i) for i in all_labels_language]

valid_data=CV.transform(validation_samples_words).toarray()
test_data=CV.transform(test_samples_words).toarray()


rfc_500 = RandomForestClassifier(n_estimators=500)
rfc_500.fit(sentences_CV, all_labels_language)
prediction=rfc_500.predict(test_data)



#print(np.mean(validation_labels_language==prediction))


rezultat = pd.DataFrame(data={"id":test_samples_index, "label": prediction} )
rezultat.to_csv("../Submission_Data/RFC_500_Submission3.csv", index = False)


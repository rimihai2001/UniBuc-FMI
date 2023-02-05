import csv
from sklearn.feature_extraction.text import CountVectorizer
import numpy as np
from sklearn.metrics import accuracy_score, confusion_matrix
import pandas as pd
from sklearn.naive_bayes import MultinomialNB


def load_text_from_file(storage1, storage2, filename, encoding, delimiter="\t"):
    f = open(filename, encoding=encoding)
    text = csv.reader(f, delimiter=delimiter)
    for elem in text:
        storage1.append(elem[0])
        storage2.append(elem[1])


train_samples_index = []
train_samples_words = []
train_labels_index = []
train_labels_language = []
test_samples_index = []
test_samples_words = []
validation_samples_words = []
validation_samples_index = []
validation_labels_index = []
validation_labels_language = []


load_text_from_file(
    train_samples_index, train_samples_words, "../data_aliens/train_samples.txt", "mbcs"
)
load_text_from_file(
    train_labels_index, train_labels_language, "../data_aliens/train_labels.txt", "utf-8"
)

load_text_from_file(
    test_samples_index, test_samples_words, "../data_aliens/test_samples.txt", "mbcs"
)

load_text_from_file(
    validation_labels_index, validation_labels_language, "../data_aliens/validation_labels.txt", "utf-8"
)

load_text_from_file(
    validation_samples_index, validation_samples_words, "../data_aliens/validation_samples.txt", "mbcs"
)


# transformarea datelor din char in int
train_samples_index = [int(i) for i in train_samples_index]
train_lables_index = [int(i) for i in train_labels_index]
train_labels_language = [int(i) for i in train_labels_language]
test_samples_index = [int(i) for i in test_samples_index]
validation_labels_index = [int(i) for i in validation_labels_index]
validation_labels_language = [int(i) for i in validation_labels_language]
validation_samples_index = [int(i) for i in validation_samples_index]

# facem un vector care contine atat datele de train, cat si datele de test
all_samples_words = train_samples_words+validation_samples_words
all_labels_language = train_labels_language+validation_labels_language


# preprocesarea datelor
CV = CountVectorizer(ngram_range=(1, 7), encoding="mbcs",
                     binary=True, analyzer="char", lowercase=False)

all_data = CV.fit_transform(all_samples_words)
validation_data = CV.transform(validation_samples_words)
test_data = CV.transform(test_samples_words)
train_data = CV.transform(train_samples_words)


# model ce se testeaza pe validare
mnb = MultinomialNB(alpha=0.1)
mnb.fit(train_data, train_labels_language)
prediction_valid = mnb.predict(validation_data)

# acuratete
print(accuracy_score(validation_labels_language, prediction_valid))

# matrice de confuzie
print(np.array(confusion_matrix(prediction_valid, validation_labels_language)))

# model ce se antreneaza doar cu datele de train
mnb = MultinomialNB(alpha=0.1)
mnb.fit(train_data, train_labels_language)
prediction_test = mnb.predict(test_data)

# model ce se antreneaza cu datele de train si validation
mnb = MultinomialNB(alpha=0.1)
mnb.fit(all_data, all_labels_language)
prediction = mnb.predict(test_data)

#afisare in CSV
pd.DataFrame(data={"id": test_samples_index, "label": prediction}).to_csv(
    "../Submission_Data/MNB_Submission10.csv", index=False)

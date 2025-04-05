import string, random

from datetime import datetime
from django.db import transaction
from faker import Faker
from mainapp.models import Book

fk=Faker()

def gendata():
    try:
        with transaction.atomic():
            for i in range(1000):
                newBook = Book()
                newBook.author = fk.random_element(('Пушкин','Лермонтов','Чехов','Другой'))
                newBook.year = fk.date_between(
                    start_date=datetime(1600, 1, 1), 
                    end_date=datetime(2025, 1, 1)
                )
                newBook.genre = fk.random_element(('Поэзия','Проза','Классика','Другой тип'))
                newBook.count = fk.random_number(2)
                newBook.is_available =  fk.random_number() > 7
                
                newBook.save()
        print('OK gentestdata')
    except Exception as e:
        print('*** ERROR gentestdata***', e)    
        
def cleardata():
    Book.objects.all().delete()
    
if  __name__=='__main__':
    gendata()            
            

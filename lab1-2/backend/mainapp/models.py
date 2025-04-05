from django.db import models

class Book(models.Model):
    author = models.CharField(max_length=64, null=True)
    year = models.DateField(null=True)
    genre = models.CharField(max_length=64, null=True)
    count = models.IntegerField(null=True)
    is_available = models.BooleanField(null=True)


from django.shortcuts import render

from django.conf import settings

import rest_framework
from rest_framework import  viewsets

from mainapp.serializers import BookSerializer


from .models import Book


class BookViewSet(viewsets.ModelViewSet):
    serializer_class = BookSerializer
    queryset = Book.objects.all()
   


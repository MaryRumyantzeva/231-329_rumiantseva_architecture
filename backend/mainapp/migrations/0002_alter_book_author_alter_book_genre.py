# Generated by Django 5.1.6 on 2025-03-06 19:27

from django.db import migrations, models


class Migration(migrations.Migration):

    dependencies = [
        ('mainapp', '0001_initial'),
    ]

    operations = [
        migrations.AlterField(
            model_name='book',
            name='author',
            field=models.CharField(max_length=64, null=True),
        ),
        migrations.AlterField(
            model_name='book',
            name='genre',
            field=models.CharField(max_length=64, null=True),
        ),
    ]

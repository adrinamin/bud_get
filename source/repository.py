""" repository.py

encapsulates the MongoClient and provides the CRUD functionality 


"""
from pymongo import MongoClient


class AccountRepository:

    def __init__(self):
        client = MongoClient('mongodb://localhost:27017/')
        db = client['account_db']
        self.__accounts__ = db['accounts']

    
    def get_accounts(self):
        return self.__accounts__
    
    def create_account(self):
        self.__db__.posts

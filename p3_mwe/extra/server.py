from fastapi import FastAPI
import os
import uvicorn


rest_api=FastAPI()

@rest_api.get("/")
async def welcome():
    return{"nachricht":"Willkommen"}

@rest_api.get("/get_offers")
async def get_offers():
    return{"offers": "x"}



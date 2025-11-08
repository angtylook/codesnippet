#!/usr/local/bin/python3
#encoding=utf-8

import asyncio

from bleak import BleakScanner, BleakClient

async def scan_devices():
    scanner = BleakScanner()
    devices = await scanner.discover()
    for device in devices:
        print("device: ", device)
        print("name: ", device.name)
        print("address: ", device.address)

# 
async def connect_and_write(address):
    async with BleakClient(address) as client:
        services = client.services
        for service in services:
            print("service uuid: ", service.uuid)
            for char in service.characteristics:
                print("  char uuid: ", char.uuid)
                print("  char properities: ", char.properties)
            if service.uuid == "0000180a-0000-1000-8000-00805f9b34fb":
                value = await client.read_gatt_char("00002a50-0000-1000-8000-00805f9b34fb")
                print(value)


loop = asyncio.get_event_loop()
#loop.run_until_complete(scan_devices())
loop.run_until_complete(connect_and_write("D0:62:2C:99:B8:9B"))





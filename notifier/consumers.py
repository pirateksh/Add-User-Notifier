import asyncio
from channels.consumer import AsyncConsumer

# Using a higher level consumer.
from channels.generic.websocket import AsyncJsonWebsocketConsumer


# Class for Echo consumer.

class EchoConsumer(AsyncConsumer):

	# Following functions are Event Handlers.

	async def websocket_connect(self, event):
		await self.send({
			"type": "websocket.accept",
		})

	# For blocking activity, we use 'await'.
	# Sending something to a client over a network is a blocking activity.

	async def websocket_receive(self, event):
		# Echo the received paylaod.
		await self.send({
			"type": "websocket.send",
			"text": event["text"],
		})


# Class for TickTockConsumer

class TickTockConsumer(AsyncJsonWebsocketConsumer):
	# In AsyncJsonWebsocketConsumer, all we have to do is just accept the connection and proceed.
	async def connect(self):
		await self.accept()
		while  1:

			# We sleep for 1 second in this infinite loop.
			await asyncio.sleep(1)

			# We will send a JSON object.
			await self.send_json("tick")

			# We again sleep for 1 second in this infinite loop.
			await asyncio.sleep(1)

			# We will send a JSON object.
			await self.send_json("........tock")

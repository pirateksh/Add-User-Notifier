import asyncio # Python library to handle asynchronous Requests
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


# Class for Add User Notifier

class NoseyConsumer(AsyncJsonWebsocketConsumer):
	# This will 'listen' to the messages sent by django signals when user is created.

	async def connect(self):
		await self.accept()

		# Retrieving the channel layer.
		# Every channel has a unique name available as slef.channel_name.
		# We added our channel to 'gossip' group.
		await self.channel_layer.group_add("gossip", self.channel_name)

		print(f"Added {self.channel_name} channel to gossip")


	async def disconnect(self, *args, **kwargs):

		# We will remove ourselves from the group/broadcast channel.
		await self.channel_layer.group_discard("gossip", self.channel_name)

		print(f"Removed {self.channel_name} channel from gossip")


	# user.gossip type event defined in signals.py is automatically translated to user_gossip event.
	async def user_gossip(self, event):
		# As soon as we receive the gossip that new user has been added, we're to broadcast this event
		# to everybody else.
		await self.send_json(event)
		print(f"Got message {event} at {self.channel_name}")

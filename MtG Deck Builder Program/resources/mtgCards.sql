USE [MtgCards]
GO

/****** Object:  Table [dbo].[cards]    Script Date: 19/04/2019 22:14:59 ******/
SET ANSI_NULLS ON
GO

SET QUOTED_IDENTIFIER ON
GO

CREATE TABLE [dbo].[cards](
	[id] [char](64) NULL,
	[oracle_id] [char](64) NULL,
	[name] [varchar](256) NULL,
	[released_at] [varchar](16) NULL,
	[layout] [varchar](32) NULL,
	[highres_image] [varchar](8) NULL,
	[image_uris] [varchar](8000) NULL,
	[mana_cost] [varchar](32) NULL,
	[cmc] [varchar](16) NULL,
	[type_line] [varchar](64) NULL,
	[oracle_text] [varchar](1024) NULL,
	[power] [varchar](8) NULL,
	[toughness] [varchar](8) NULL,
	[colors] [varchar](32) NULL,
	[color_identity] [varchar](32) NULL,
	[legailities] [varchar](8000) NULL,
	[nonfoil] [varchar](8) NULL,
	[oversized] [varchar](8) NULL,
	[promo] [varchar](8) NULL,
	[reprint] [varchar](8) NULL,
	[set_name] [varchar](128) NULL,
	[rulings_uri] [varchar](256) NULL,
	[collector_number] [varchar](8) NULL,
	[digital] [varchar](8) NULL,
	[rarity] [varchar](8) NULL,
	[artist] [varchar](64) NULL,
	[border_color] [varchar](16) NULL,
	[frame] [varchar](8) NULL,
	[story_spotlight] [varchar](8) NULL
) ON [PRIMARY]
GO

